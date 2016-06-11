#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
#define CLIENT_START "{\"text\":\"Client Started\"}"
#define CLIENT_STOP  "{\"text\":\"Client Stopped\"}"
#define CLIENT_CLICK  "{\"text\":\"Client Click\"}"

inline QString sendMessage(QString data)
{
    unsigned int len = data.length();
    cout.write(reinterpret_cast<const char *>(&len), 4);
    cout << data.toUtf8().data() << flush;
    return "";
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    QString datas="App running with args=";
    datas.append(QString::number(qApp->arguments().count())).append("\n");
    int i=0;
    foreach(QString s,qApp->arguments())
    {
        datas.append(QString::number(i)).append(" : ").append(s); i++;
    }
    QThread *thread = new QThread(this);
    Worker *updater = new Worker();
    updater->moveToThread(thread);
    connect(updater, SIGNAL(UpdateMessage(QString)), this, SLOT(UpdateNewMessage(QString)));
    connect(thread, SIGNAL(destroyed()), updater, SLOT(deleteLater()));
    updater->start();

    ui->plainTextEdit->appendPlainText("\nGoogle Chrome Native Messaging App V1\n\n GPLV3 software distributed under the License is distributed on an \"AS IS\" BASIS\n" \
                                       "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n" \
                                       "See the License for the specific language governing permissions and\n" \
                                       "limitations under the License.\n");

    ui->plainTextEdit->appendPlainText(datas+"\n\nClient Started..");
    sendMessage(CLIENT_START);
}

MainWindow::~MainWindow()
{
    ui->plainTextEdit->appendPlainText("Client Stopped..");
    sendMessage(CLIENT_STOP);
    delete ui;
}

void MainWindow::UpdateNewMessage(const QString &msg)
{
    int cnt = ui->plainTextEdit->toPlainText().count();
    if(cnt>1024)
        ui->plainTextEdit->clear();

    ui->plainTextEdit->appendPlainText("Receving data from plugin <-<- "+msg);

}

void MainWindow::on_SendMessage_clicked()
{    
 //   sendMessage(CLIENT_CLICK);
    QString msg;
    msg.append("{\"text\":\"").append(ui->teMessage->document()->toPlainText()).append("\"}");
    sendMessage(msg);
    ui->plainTextEdit->appendPlainText(msg.prepend("Sending data to plugin ->-> "));
}
