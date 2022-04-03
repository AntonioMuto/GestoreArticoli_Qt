#ifndef AUTORE_H
#define AUTORE_H
#include <string>
#include <QMainWindow>
using namespace std;

class Autore{

 private:
QString identificativo;
QString nome;
QString cognome;
QList<QString> afferenze;


 public:

Autore(){
  identificativo = "";
  nome = "";
  cognome = "";
}

Autore(QString i, QString n, QString c)
{
  identificativo=i;
  nome=n;
  cognome=c;
}

void aggiungiAfferenza(QString s){
    afferenze.push_back(s);
}

QStringList visualizzaAfferenza(){
 QStringList Affer;
    for(auto it = afferenze.begin(); it != afferenze.end(); ++it){
       Affer.push_back(*it);
    }
  return Affer;
}

QString getNome(){
  return nome;
}

void setNome(QString n){
  nome = n;
}

QString getId(){
  return identificativo;
}

void setId(QString i){
  identificativo = i;
}

QString getCognome(){
  return cognome;
}

void setCognome(QString c){
  cognome = c;
}

};
#endif // AUTORE_H
