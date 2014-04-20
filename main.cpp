#include <QCoreApplication>
#include <QDebug>
#include <QImage>
#include <iostream>

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

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                count++;
                std::cout << my_image->pixel(i,j) << "\t";
            }
            std::cout << "\n";
        }
        qDebug() << "[debug]: total pixel " << count ;

    }

    return 0;
}
