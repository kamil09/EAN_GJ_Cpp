#include "plik.h"


QString** readFile(QString filename, int* varCount, int* rowCount,QString **tab){
    QFile file(filename);
     if (!file.open (QIODevice::ReadOnly))  return NULL;

    QTextStream in(&file);
    int k=0;
    if(in.atEnd()) return NULL;
    QString line = in.readLine();
    *rowCount = line.toInt();
    if(in.atEnd()) return NULL;
    line = in.readLine();
    *varCount = line.toInt();


   tab = new QString*[*rowCount +1];
   for(int i = 0; i <= *rowCount; ++i)
       tab[i] = new QString[*varCount + 1];

    while (!in.atEnd()) {
         line = in.readLine();
         QStringList fields = line.split(" ");
         for(int i=0;i<*varCount;i++)
            tab[k][i]=fields.at(i);
         k++;
         if(k==*rowCount) break;
    }
    file.close();
    return tab;
}

