#ifndef ARTICOLO_H
#define ARTICOLO_H
#include "Autore.h"
#include <string>
#include <QListWidgetItem>
#include <QList>
using namespace std;


class Articolo {

 private:
QString identificativo;
QString titolo;
int numeropag;
QList<Autore*> autori;
QList<QString> keyword;
float prezzo;
QList<Articolo*> articoli_corr;
QString data_pubblicazione;
 public:

Articolo(){
   identificativo = "";
   titolo = "";
   numeropag = 0;
   prezzo = 0.0;
}

Articolo(QString i, QString t, int num, float p){
    identificativo = i;
    titolo = t;
    numeropag = num;
    prezzo = p;
}

bool keywordPresente(QString k){
 for(auto it = keyword.begin(); it != keyword.end(); ++it){
  if((*it) == k){
     return true;
  }
 }
 return false;
}

void aggiungiKeyword(QString k){
   keyword.push_back(k);
}

void rimuoviAutore(int i){
   autori.removeAt(i);
}

QList<Autore*> getAutori(){
  QList<Autore*> elenco;
    for(auto it = autori.begin(); it != autori.end(); ++it){
       elenco.push_back(*it);
    }
  return elenco;
}

QList<QString> getKeywords(){
  QList<QString> elenc;
    for(auto it = keyword.begin(); it != keyword.end(); ++it){
       elenc.push_back(*it);
    }
  return elenc;
}

QString getAnno(){
  QString s = data_pubblicazione;
  QStringList a = s.split("/");
  foreach (QString y, a) {
     s = y;
    break;
  }
  return s;
}

QString getPrimoAutore(){
  QString a;

  a = autori[0]->getCognome();
  return a;
}

QString getData(){
    return data_pubblicazione;
}

void setData(QString x){
   data_pubblicazione = x;
}


bool aggiungiAutore(Autore* a){

   for(auto it = autori.begin(); it != autori.end(); ++it){
      if(a->getId() == (*it)->getId()){
          return false;
      }
   }

    autori.push_back(a);
    return true;
}

void aggiungiArticoloCorrellato(Articolo* a){
    articoli_corr.push_back(a);
}


QString getTitolo(){
  return titolo;
}

void setTitolo(QString t){
  titolo = t;
}


QString getId(){
  return identificativo;
}

void setId(QString i){
 identificativo = i;
}

int getNumPag(){
  return numeropag;
}

void setNumPag(int p){
 numeropag = p;
}

float getPrezzo(){
 return prezzo;
}

void setPrezzo(float p){
 prezzo = p;
}



};

#endif // ARTICOLO_H
