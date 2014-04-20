#include <QCoreApplication>
#include <QDebug>
#include <QImage>
#include <iostream>
#include <QRgb>
#include <QString>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(argc!=2){
        qDebug() << "Usage: ./image2data <Image File>";
        qDebug() << argc;

    }else{
        qDebug() << argv[0];
        qDebug() << argv[1];
        int count = 0;
        QImage *my_image = new QImage(argv[1]);
        int row,col;
        row = my_image->size().height();
        col = my_image->size().width();
        QString rgb_value;
        QStringRef ref_value;
        std::cout << "const int img[] = { \n";
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                count++;
                int value = my_image->pixel(i,j);
                rgb_value = QString::number(value, 16);
                ref_value= rgb_value.rightRef(6);
                rgb_value = "0x"+ref_value.toString();
                std::cout << rgb_value.toStdString() << ", ";
//                qDebug()<< rgb_value <<",";
            }
            std::cout << "\n";
        }
        std::cout <<"};";
        //qDebug() << "[debug]: total pixel " << count ;

    }

    return 0;
}
