#ifndef CONFERENZA_H
#define CONFERENZA_H
#include "Pubblicazione.h"
using namespace std;

class Conferenza: public Pubblicazione{

 private:
QString luogo;
QList<QString> organizzatori;
int partecipanti;
 public:

Conferenza(): Pubblicazione(), partecipanti(0){
}

Conferenza(QString n, QString a, QString d,QString l,int p, QStringList o, QList<Articolo*> x, bool c): Pubblicazione(n,a,d,x,c,o), luogo(l), partecipanti(p) {
}

QStringList getOrganizzatori(){
  QStringList orga;
  foreach(QString x, organizzatori){
      orga.push_back(x);
  }
  return orga;
}


int getPartecipanti(){
 return partecipanti;
}

void setPartecipanti(int p){
  partecipanti = p;
}

QString getLuogo(){
 return luogo;
}

void setLuogo(QString l){
  luogo = l;
}


void aggiungiOrganizzatore(QString s){
    organizzatori.push_back(s);
}

QStringList visualizzaOrganizzatori(){
 QStringList organ;
    for(auto it = organ.begin(); it != organ.end(); ++it){
       organ.push_back(*it);
    }
  return organ;
}

};

#endif // CONFERENZA_H
