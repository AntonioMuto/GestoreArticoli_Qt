#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H
#include <QString>
#include <QList>
#include "Articolo.h"
#include "Conferenza.h"
using namespace std;

class Pubblicazione{
  private:
QString nome;
QString acronimo;
QString data;
QList<Articolo*> elenco;
bool conferenza;
QList<QString> organizzatori;

  public:
Pubblicazione(){
}

Pubblicazione(QString n, QString a, QString d,QList<Articolo*> x, bool c,QStringList o){
    nome = n;
    acronimo = a;
    data = d;
    conferenza = c;
    foreach(QString s, o){
      organizzatori.push_back(s);
    }
}

virtual ~Pubblicazione(){
}

virtual Pubblicazione* clone() const
{
  return new Pubblicazione(*this);
}

QStringList getOrganizzatori(){
    QStringList orga;
    foreach(QString x, organizzatori){
        orga.push_back(x);
    }
    return orga;
}


QList<Articolo*> getArticoli(){
   QList<Articolo*> list = elenco;
     return list;
}

void aggiungiOrganizzatore(QString o){
  organizzatori.push_back(o);
}

bool getPubblicazione(){
   return conferenza;
}

void setPubblicazione(bool f){
   conferenza = f;
}

void aggiungiArticolo(Articolo* a){
    elenco.push_back(a);
}

QList<Articolo*> getListArt(){
  QList<Articolo*> x;
   for(auto it = elenco.begin(); it != elenco.end(); ++it){
     x.push_back(*it);
   }
  return x;
}


QString getNome(){
   return nome;
}

void setNome(QString n){
 nome = n;
}

QString getAcronimo(){
  return acronimo;
}

void setAcronimo(QString a){
  acronimo = a;
}

QString getData(){
 return data;
}

QString getAnno(){
  QString s = data;
  QStringList a = s.split("/");
  foreach (QString y, a) {
     s = y;
    break;
  }
  return s;
}


void setData(QString d){
 data = d;
}

};



#endif // PUBBLICAZIONE_H
