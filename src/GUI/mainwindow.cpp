#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString p_q,t_q;
    p_q=ui->plainTextEdit->toPlainText();
    t_q=ui->plainTextEdit_2->toPlainText();
    string p,t;
    p=p_q.toStdString();
    t=t_q.toStdString();
    test.input(p,t);
    test.run();
    QString ans;
    for(auto j:test.kmp.ans)
        ans+=QString("%1\n").arg(j);
    ui->textBrowser->setText(ans);
    ui->textBrowser_2->setText(QString("%1").arg(test.timecost[0]));
    ui->textBrowser_3->setText(QString("%1").arg(test.timecost[1]));
    ui->textBrowser_4->setText(QString("%1").arg(test.timecost[2]));
}

void MainWindow::on_pushButton_4_clicked()
{
    filename=ui->lineEdit->text();
    ifstream in(filename.toStdString());
    if(in.fail())
    {
        QMessageBox::warning(this, tr("Read File"),
                                         tr("Cannot open file:\n%1").arg(filename));
        return;
    }

    string p,t;
    in>>p;
    in>>t;
    test.input(p,t);
    test.run();
    /*
    ui->textBrowser_5->setText("0");
    for(int i=0;i<test.bf.ans.size();i++)
    {
        if(test.bf.ans[i]!=test.bm.ans[i])
        {
            ui->textBrowser_5->setText("1");
            break;
        }

    }
    for(int i=0;i<test.bm.ans.size();i++)
    {
        if(test.bf.ans[i]!=test.bm.ans[i])
        {
            ui->textBrowser_5->setText("1");
            break;
        }

    }
    */
    QString ans;
    for(auto j:test.bf.ans)
        ans+=QString("%1\n").arg(j);
    ui->textBrowser_2->setText(QString("%1").arg(test.timecost[0]));
    ui->textBrowser_3->setText(QString("%1").arg(test.timecost[1]));
    ui->textBrowser_4->setText(QString("%1").arg(test.timecost[2]));
    int n=filename.size();
    filename.replace(n-4,4,"_output.txt");
    ofstream out(filename.toStdString());
    if(!out.fail())
    {
        out<<ans.toStdString();
        QMessageBox::information(this, tr("结果"),
                                         tr("结果已输出至:\n%1").arg(filename));
    }
    else {
        QMessageBox::warning(this, tr("Read File"),
                                         tr("Cannot open file:\n%1").arg(filename));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    filename=QFileDialog::getOpenFileName(this,
                                          tr("Open File"),
                                          ".",
                                          tr("Text Files(*.txt)"));
    ui->lineEdit->setText(filename);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    ui->textBrowser_4->clear();
}
