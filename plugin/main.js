// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var port = null;

var getKeys = function(obj){
   var keys = [];
   for(var key in obj){
      keys.push(key);
   }
   return keys;
}

function appendMessage(text) {
  document.getElementById('response').innerHTML += "<p>" + text + "</p>";
}

function updateUiState() {
  if (port) {
    document.getElementById('connect-button').style.display = 'none';
    document.getElementById('input-text').style.display = 'block';
    document.getElementById('send-message-button').style.display = 'block';
	document.getElementById('download-button').style.display = 'none';
  } else {
    document.getElementById('connect-button').style.display = 'block';
    document.getElementById('input-text').style.display = 'none';
    document.getElementById('send-message-button').style.display = 'none';
	document.getElementById('download-button').style.display = 'block';
  }
}

function sendNativeMessage() {
  message = {"text": document.getElementById('input-text').value};
  port.postMessage(message);
  appendMessage("Sent message: <b>" + JSON.stringify(message) + "</b>");
}

function onNativeMessage(message) {
  appendMessage("Received message: <b>" + JSON.stringify(message) + "</b>");
}

function onDisconnected() {
  appendMessage("Failed to connect: " + chrome.runtime.lastError.message);
    if ( chrome.runtime.lastError.message=="Specified native messaging host not found." ) {
    appendMessage("More information on <a href=\"http://coderbox.in/Google/Plugin\">http://coderbox.in/Google/Plugin</a>");
//https://github.com/Mandar-Shinde/Google-Chrome-Native-Messaging/archive/NativeClientQtC++.exe
}
  port = null;
  updateUiState();
}

function downloadClient() {
    window.open('https://github.com/Mandar-Shinde/Google-Chrome-Native-Messaging/releases/download/V1.0/GoogleNativeClient.exe');
}

function connect() {
  var hostName = "com.google.chrome.example.echo.mandar.shinde";
  appendMessage("Connecting to native messaging host <b>" + hostName + "</b>")
  port = chrome.runtime.connectNative(hostName);
  port.onMessage.addListener(onNativeMessage);
  port.onDisconnect.addListener(onDisconnected);
  updateUiState();
}

document.addEventListener('DOMContentLoaded', function () {
  document.getElementById('connect-button').addEventListener(
      'click', connect);
  document.getElementById('send-message-button').addEventListener(
      'click', sendNativeMessage);
	   document.getElementById('download-button').addEventListener(
      'click', downloadClient);
  updateUiState();
});
