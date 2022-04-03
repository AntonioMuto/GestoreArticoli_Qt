#ifndef RIVISTA_H
#define RIVISTA_H
#include "Pubblicazione.h"
using namespace std;

class Rivista: public Pubblicazione{

 private:
QString editore;
int volume;
 public:

Rivista(): Pubblicazione(), editore(""), volume(0){
}

Rivista(QString n, QString a, QString d, QString e, int v, QList<Articolo*> x, bool c,QStringList o): Pubblicazione(n,a,d,x,c,o), editore(e), volume(v) {
}

QString getEditore(){
 return editore;
}

void setEditore(QString e){
 editore = e;
}

int getVolume(){
 return volume;
}

void setVolume(int v){
 volume = v;
}

};



#endif // RIVISTA_H
