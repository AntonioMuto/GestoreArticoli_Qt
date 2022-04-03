#include "gestore.h"
#include "ui_gestore.h"
#include "Articolo.h"
#include "Conferenza.h"
#include "Rivista.h"
#include <QMessageBox>
#include <QString>
using namespace std;


Gestore::Gestore(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestore)
{
    ui->setupUi(this);

}

Gestore::~Gestore()
{
    delete ui;
}


void Gestore::on_Bottone_autore_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->pagina_autore);
}


void Gestore::on_Bottone_conferenza_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->pagina_conferenza);
}

void Gestore::on_Bottone_rivista_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->pagina_rivista);
}

void Gestore::on_Bottone_articolo_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->pagina_articolo);
}


void Gestore::on_Aggiungi_clicked()
{

   Articolo* x = new Articolo();

   QString ID = "ID: ";
   QString TITOLO = " Titolo: ";
   QString NUMPAG = "Pag:";
   QString PREZZO = "€";
   QString sp = "   ";
   QString ident = ui->TestoId->toPlainText();
   QString titolo = ui->TestoTitolo->toPlainText();
   QString _numpag = (QString::number(1) =ui->TestoNumpag->toPlainText());
   QString _prez = (QString::number(1) = ui->TestoPrezzo->toPlainText());
   QString completa = ui->TestoKeyword->toPlainText();
   QStringList strsplit = completa.split("\n");
   foreach (QString s, strsplit) {
    x->aggiungiKeyword(s);
   }

   int numpag = _numpag.toInt();
   float prez = _prez.toFloat();
   int idx = 0;

   if(ident.isEmpty() || titolo.isEmpty() || _numpag.isEmpty() || _prez.isEmpty() || completa.isEmpty()){
       QMessageBox mess(QMessageBox::Critical,"Errore","I campi: Identificativo, Titolo, Numero di pagine e Prezzo non possono essere vuoti.", QMessageBox::Ok,this);
       mess.exec();
       return;
   }


   x->setId(ident);
   x->setTitolo(titolo);
   x->setNumPag(numpag);
   x->setPrezzo(prez);


   ui->TestoTitolo->clear();
   ui->TestoNumpag->clear();
   ui->TestoPrezzo->clear();
   ui->TestoId->clear();
   ui->TestoKeyword->clear();

   ID += ident + sp + TITOLO + titolo + sp + NUMPAG + _numpag + sp + PREZZO + _prez;

   if(ui->Lista_Articoli->selectedItems().size() <= 0){
     ui->Lista_Articoli_in_Autori->addItem(ID);
     ui->Lista_Articoli->addItem(ID);
     ui->ListaArticoli->addItem(ID);
     ui->LIsta_vis_articoli->addItem(ID);
     articoli_gest.push_back(x);
     return;
   }
   else{
       QListWidgetItem* item = getItem(ui->Lista_Articoli);
        idx = getIndex(item, ui->Lista_Articoli);
       auto it = articoli_gest.at(idx);
       it->aggiungiArticoloCorrellato(x);
       ui->Lista_Articoli->clearSelection();
          return;
   }
}



void Gestore::on_Bottone_Add_Autore_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Pagina_aggiungi_Autore);
}

void Gestore::on_tornamenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Bottone_Add_Articolo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_AddArticolo);
}

void Gestore::on_Bottone_Add_COnferenza_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_aggiungi_Conferenza);
}

void Gestore::on_tornamenu_Addconf_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}


void Gestore::on_tornamenu_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Bottone_Add_Rivista_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_AddRivista);
}



void Gestore::on_Elimina_list_clicked()
{
  QListWidgetItem* NAME = getItem(ui->ListaAutori);

  int idx = getIndex(NAME,ui->ListaAutori);
  autori_gest.takeAt(idx);
  ui->ListaAutori->removeItemWidget(NAME);
  QString cont = QString::number(autori_gest.size());
  ui->lcdNumber->display(cont);
}

int Gestore::getIndex(QListWidgetItem* item, QListWidget* a){
    for(int i = 0 ;i < a->count();i++){
        if(item == a->item(i)){
           return i;
        }
    }
  return 99999;
}

QListWidgetItem* Gestore::getItem(QListWidget* a){
QList<QListWidgetItem*> elenco;
elenco = a->selectedItems();
return elenco.front();
}

void Gestore::on_Elimina_Articoli_clicked()
{
  QListWidgetItem* a = getItem(ui->Lista_Articoli);
  QListWidgetItem* b = getItem(ui->Lista_Articoli);
  int idxb = getIndex(b,ui->Lista_Articoli);
  int idxa = getIndex(a,ui->Lista_Articoli);

  delete ui->Lista_Articoli->takeItem(idxa);
  delete ui->Lista_Articoli_in_Autori->takeItem(idxb);

  articoli_gest.removeAt(idxa);
}

void Gestore::on_tornamenu_5_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Bottone_inserisci_Autore_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Pagina_Inserisci_Autore);
}

void Gestore::on_AggiungiAutore_2_clicked()
{
   Autore* x = new Autore();

    QString ID = "ID: ";
    QString NOME = "Nome: ";
    QString COGNOME = "Cognome: ";
    QString sp = "  ";
    QString id = ui->testoId->toPlainText();
    QString nome = ui->testoNome->toPlainText();
    QString cognome = ui->testoCognome->toPlainText();

    if(id.isEmpty() || nome.isEmpty() || cognome.isEmpty()){
        QMessageBox mess(QMessageBox::Critical,"Errore","I campi: Identificativo, Nome e Cognome non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    ID += id + sp + NOME + nome + sp + COGNOME + cognome;

    ui->ListaAutori_agg->addItem(ID);
    ui->ListaAutori->addItem(ID);

    ui->testoId->clear();
    ui->testoNome->clear();
    ui->testoCognome->clear();

    x->setNome(nome);
    x->setId(id);
    x->setCognome(cognome);

    QString completa = ui->testoAfferenze->toPlainText();
    QStringList strsplit = completa.split("\n");
    foreach (QString s, strsplit) {
     x->aggiungiAfferenza(s);
    }
    autori_gest.push_back(x);
    QString cont = QString::number(autori_gest.size());
    ui->lcdNumber->display(cont);
    ui->lista_vis_autori->addItem(ID);
    ui->Lista_autori_rivpub->addItem(ID);
    ui->testoAfferenze->clear();
}

void Gestore::on_Elimina_Autori_2_clicked()
{
    QListWidgetItem* a = getItem(ui->ListaAutori_agg);
    int idxa = getIndex(a,ui->ListaAutori_agg);

    delete ui->ListaAutori_agg->takeItem(idxa);
    articoli_gest.removeAt(idxa);
    ui->lcdNumber->display(articoli_gest.size());

}

void Gestore::on_pushButton_clicked()
{
    if(ui->Lista_Articoli_in_Autori->selectedItems().size() <= 0){
        QMessageBox mess(QMessageBox::Critical,"Errore","Nessun elemento della lista articoli è stato selezionato", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(ui->ListaAutori->selectedItems().size() <= 0){
        QMessageBox mess(QMessageBox::Critical,"Errore","Nessun elemento della lista autori è stato selezionato", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    QListWidgetItem* item = getItem(ui->Lista_Articoli_in_Autori);
    QListWidgetItem* itema = getItem(ui->ListaAutori);
    int idxa = getIndex(itema, ui->ListaAutori);
    int idx = getIndex(item, ui->Lista_Articoli_in_Autori);
    if(articoli_gest.at(idx)->aggiungiAutore(autori_gest.at(idxa)) == false){

        ui->Lista_Articoli_in_Autori->clearSelection();
        ui->ListaAutori->clearSelection();


        QMessageBox mess(QMessageBox::Critical,"Errore","Autore già presente nell'articolo", QMessageBox::Ok,this);
        mess.exec();
        return;
    }
    else{

        ui->Lista_Articoli_in_Autori->clearSelection();
        ui->ListaAutori->clearSelection();

        QMessageBox mess(QMessageBox::Critical,"Fatto","Autore aggiunto nell'articolo", QMessageBox::Ok,this);
        mess.exec();
        return;
    }
}

void Gestore::on_tornamenu_6_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu_7_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Bottone_Add_Autore_2_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_visualizza_Autori);
}

void Gestore::on_lista_vis_autori_itemClicked(QListWidgetItem *item)
{
    QStringList articoliord;
    ui->lista_Articoli_autore->clear();
    ui->lista_vis_Afferenze->clear();
    int idxa = getIndex(item, ui->lista_vis_autori);
    auto it = autori_gest.at(idxa);
     QStringList a = it->visualizzaAfferenza();
     for(auto ite = a.begin(); ite != a.end(); ++ite){
         ui->lista_vis_Afferenze->addItem(*ite);
     }
    ui->lista_vis_autori->clearSelection();

    QString id = autori_gest.at(idxa)->getId();
    bool trovato = false;
    bool anno = false;
    int cont = 0, cont_media = 0;
    double prezzo = 0.0;
    for(auto it = articoli_gest.begin(); it != articoli_gest.end();++it){
         QList<Autore*> x  = (*it)->getAutori();
           for(auto l = x.begin(); l != x.end();++l){
             if((**l).getId() == id){
               prezzo += (*it)->getPrezzo();
               cont_media++;
               if(ui->radio_Anno_crescente->isChecked() == false){
                 ui->lista_Articoli_autore->addItem(ui->LIsta_vis_articoli->item(cont)->text());
                 trovato = true;
               }
               if(ui->radio_Anno_crescente->isChecked() == true){
                 articoliord.push_back(ui->LIsta_vis_articoli->item(cont)->text());
                 anno = true;
                 trovato = true;
               }
            }
           }
      cont++;
    }

  if(!trovato){
    QString err = "NESSUN ARTICOLO PRESENTE ";
    ui->lista_Articoli_autore->addItem(err);
  }
  if(anno){
    ordinaArticoloAnnoCre(articoliord);
  }
 ui->lcd_prezzo->display(prezzo/cont_media);
}


void Gestore::ordinaArticoloAnnoCre(QStringList a)
{
 QVector<QString> articoli;
 QVector<QString> date;
  for(auto l= a.begin(); l != a.end();++l){
   for(int i = 0; i < ui->LIsta_vis_articoli->count(); i++){
      if(ui->LIsta_vis_articoli->item(i)->text() == (*l)){
        if(a.size() == 1){
           ui->LIsta_vis_articoli->item(i)->text();
           return;
        }
        date.push_back(articoli_gest.at(i)->getData());
        articoli.push_back(ui->LIsta_vis_articoli->item(i)->text());
      }
   }
  }

bool swap = false;
 while(!swap){
   swap = true;
  for(int i = 0; i < articoli.size()-1; i++){
      if(date[i] > date[i+1] ){
       articoli.swapItemsAt(i,i+1);
       date.swapItemsAt(i,i+1);
       swap = false;
       break;
      }
    }
  }

  for(int i=0;i < articoli.size();i++){
    ui->lista_Articoli_autore->addItem(articoli[i]);
   }

}


void Gestore::on_Bottone_Pub_Articolo_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_pubblica_Articolo);
}

void Gestore::on_Pubblica_clicked()
{
    if(ui->ListaArticoli->selectedItems().size() <= 0){
        QMessageBox mess(QMessageBox::Critical,"Errore","Nessun elemento della lista articoli è stato selezionato", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(!ui->radio_Rivista->isChecked() && !ui->radio_conferenza->isChecked()){
        QMessageBox mess(QMessageBox::Critical,"Errore","Scegliere almeno un luogo dove pubblicare l'articolo", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(!ui->radio_Rivista->isChecked() && ui->radio_conferenza->isChecked()){
        int idx = 0;
        QString s = ui->comboBox_Conferenza->currentText();

        for(int i=0;i < ui->Lista_conf_riv->count(); i++){
            if(ui->Lista_conf_riv->item(i)->text() == s){
               idx = i;
            }
        }
        QListWidgetItem* x = getItem(ui->ListaArticoli);
        int idxt = getIndex(x,ui->ListaArticoli);
        int idxa = 0;

        QString t = ui->ListaArticoli->item(idxt)->text();
         for(int i = 0; i < ui->LIsta_vis_articoli->count(); i++){
            if(t == ui->LIsta_vis_articoli->item(i)->text()){
               idxa = i;
            }
         }
        ui->ListaArticoli->takeItem(idxt);
        elenco_pubbl.at(idx)->aggiungiArticolo(articoli_gest.at(idxa));
        articoli_gest.at(idxa)->setData(elenco_pubbl.at(idx)->getData());
        ui->Lista_Pubb_Conferenze->addItem(t);
        ui->ListaArticoli->clearSelection();
    }

   if(ui->radio_Rivista->isChecked() && !ui->radio_conferenza->isChecked()){
       int idx = 0;
       QString s = ui->comboBox_Rivista->currentText();
       for(int i=0;i < ui->Lista_conf_riv->count(); i++){
           if(ui->Lista_conf_riv->item(i)->text() == s){
              idx = i;
           }
       }
       QListWidgetItem* x = getItem(ui->ListaArticoli);
       int idxt = getIndex(x,ui->ListaArticoli);
       int idxa = 0;
       QString t = ui->ListaArticoli->item(idxt)->text();
        for(int i = 0; i < ui->LIsta_vis_articoli->count(); i++){
           if(t == ui->LIsta_vis_articoli->item(i)->text()){
              idxa = i;
           }
        }
       ui->ListaArticoli->takeItem(idxt);
       elenco_pubbl.at(idx)->aggiungiArticolo(articoli_gest.at(idxa));
       articoli_gest.at(idxa)->setData(elenco_pubbl.at(idx)->getData());
       ui->Lista_Pubb_Riviste->addItem(t);
       ui->ListaArticoli->clearSelection();
   }

}

void Gestore::on_Bottone_Aggiungi_conf_clicked()
{
     QString confe = "CONFERENZA: ";
     QString sp = "  ";
     QString acronimo = ui->TestoAcronimo_conf ->toPlainText();
     QString nome = ui->TestoNome_conf ->toPlainText();
     QString partecipanti = ui->TestoPartecipanti_conf->toPlainText();
     QString data = on_calendarWidget_clicked();
     QString luogo = ui->TestoLugo_conf->toPlainText();
     int  p = partecipanti.toInt();
     QString completa = ui->TestoOrganizzatori_conf->toPlainText();
     QStringList strsplit = completa.split("\n");
     QStringList list;
     foreach (QString s, strsplit) {
        list.push_back(s);
     }
     if(nome.isEmpty() || acronimo.isEmpty() || data.isEmpty() || partecipanti.isEmpty() || luogo.isEmpty() || list.isEmpty()){
         QMessageBox mess(QMessageBox::Critical,"Errore","I campi: Nome, Cognome, Acronimo, Partecipanti, Luogo e organizzatori non possono essere vuoti.", QMessageBox::Ok,this);
         mess.exec();
         return;
     }
     Pubblicazione* c = new Conferenza(nome,acronimo,data,luogo,p,list,articoli_gest,true);
     QString conf = confe + nome + sp + acronimo + sp + partecipanti + sp + data + sp + luogo;
     bool esiste = false;
      for(auto it = elenco_pubbl.begin(); it != elenco_pubbl.end(); ++it){
         if((*it)->getAnno() == c->getAnno() && (*it)->getNome() == c->getNome() && (*it)->getPubblicazione() == true){
             esiste = true;
             QMessageBox mess(QMessageBox::Critical,"Errore","Esiste già una conferenza in quest'Anno con questo Nome", QMessageBox::Ok,this);
             mess.exec();
             return;
         }
      }
      if(!esiste){
          ui->ListaConferenze_agg_->addItem(conf);
          ui->comboBox_Conferenza->addItem(conf);
          ui->Lista_conf_riv->addItem(conf);
          ui->Lista_vis_Conferenza->addItem(conf);
         elenco_pubbl.push_back(c);
      }

     ui->TestoAcronimo_conf->clear();
     ui->TestoOrganizzatori_conf->clear();
     ui->TestoData_conf->clear();
     ui->TestoNome_conf->clear();
     ui->TestoLugo_conf->clear();
     ui->TestoPartecipanti_conf->clear();
}



void Gestore::on_Bottone_Aggiungi_Rivista_clicked()
{
    QString rivista = "RIVISTA: ";
    QString sp = "  ";
    QString acronimo = ui->TestoAcronimo_riv ->toPlainText();
    QString nome = ui->TestoNome_riv ->toPlainText();
    QString volume = ui->TestoVolume_riv->toPlainText();
    QString data = on_data_riv_clicked();
    QString editore = ui->TestoEditore_riv->toPlainText();
    QStringList l;

    if(nome.isEmpty() || acronimo.isEmpty() || data.isEmpty() || volume.isEmpty() || editore.isEmpty()){
        QMessageBox mess(QMessageBox::Critical,"Errore","I campi: Nome, Cognome, Acronimo, data, editore e volume non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

   QString riv = rivista + nome + sp + acronimo + sp + data + sp + editore + sp + volume;
    Pubblicazione* r = new Rivista(nome,acronimo,data,editore,volume.toInt(),articoli_gest,false,l);
    bool esiste = false;
     for(auto it = elenco_pubbl.begin(); it != elenco_pubbl.end(); ++it){
        if((*it)->getAnno() == r->getAnno() && (*it)->getNome() == r->getNome() && (*it)->getPubblicazione() == false){
            esiste = true;
            QMessageBox mess(QMessageBox::Critical,"Errore","Esiste già una rivista in quest'Anno con questo Nome", QMessageBox::Ok,this);
            mess.exec();
            return;
        }
     }
     if(!esiste){
       ui->ListaRivista->addItem(riv);
       ui->comboBox_Rivista->addItem(riv);
       ui->Lista_conf_riv->addItem(riv);
       ui->Lista_vis_riviste->addItem(riv);
       elenco_pubbl.push_back(r);
     }

    ui->TestoAcronimo_riv->clear();
    ui->TestoEditore_riv->clear();
    ui->TestoData_riv->clear();
    ui->TestoNome_riv->clear();
    ui->TestoVolume_riv->clear();
}

QString Gestore::on_data_riv_clicked()
{
    QDate s = ui->data_riv->selectedDate();
    QString data = QString::number(s.year()) + "/" + QString::number(s.month()) + "/" + QString::number(s.day());
    ui->TestoData_riv->setPlainText(data);
    return data;
}

QString Gestore::on_calendarWidget_clicked()
{
    QDate s = ui->calendarWidget->selectedDate();
    QString data = QString::number(s.year()) + "/" + QString::number(s.month()) + "/" + QString::number(s.day());
    ui->TestoData_conf->setPlainText(data);
    return data;
}

void Gestore::on_tornamenu_8_clicked()
{
   ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Bottone_Add_Rivista_2_clicked()
{
   ui->stackedWidget->setCurrentWidget(ui->pagina_visualizza_riviste);
}

void Gestore::on_Lista_vis_Conferenza_itemClicked(QListWidgetItem *item)
{
    ui->Lista_vis_articolo_conferenza->clear();
    int idx = 0;
    ui->Lista_vis_Organizzatori->clear();
    for(int i=0;i < ui->Lista_conf_riv->count();i++){
         if(item->text() == ui->Lista_conf_riv->item(i)->text()){
            idx = i;
         }
    }
      Pubblicazione* x = elenco_pubbl.at(idx);
      QStringList a = x->getOrganizzatori();
      foreach(QString s, a){
         ui->Lista_vis_Organizzatori->addItem(s);
      }
     QList<Articolo*> listart = x->getArticoli();
       for(auto it = listart.begin(); it != listart.end(); ++it){
           for(int i = 0; i < ui->LIsta_vis_articoli->count(); i++){
             if((**it).getId() == articoli_gest.at(i)->getId()){
              ui->Lista_vis_articolo_conferenza->addItem(ui->LIsta_vis_articoli->item(i)->text());
              break;
             }
           }
       }


 ui->lista_vis_autori->clearSelection();
}

void Gestore::on_Bottone_Add_COnferenza_2_clicked()
{
   ui->stackedWidget->setCurrentWidget(ui->pagina_vis_conferenze);
}

void Gestore::on_tornamenu_Addconf_2_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu_9_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_tornamenu_10_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Bottone_Pub_Articolo_3_clicked()
{
  if(ui->comboBox_vis_Articoli->currentText() == "ricerca tramite keyword"){
   ui->stackedWidget->setCurrentWidget(ui->pag_vis_tramite_keyword);
  }
  if(ui->comboBox_vis_Articoli->currentText() == "visualizzazione standard"){
   ui->stackedWidget->setCurrentWidget(ui->pag_vis_articoli);
  }
}


void Gestore::on_LIsta_vis_articoli_itemClicked(QListWidgetItem *item)
{
    int idx = 0;
    ui->Lista_vis_keyword->clear();
    for(int i=0;i < ui->LIsta_vis_articoli->count();i++){
         if(item->text() == ui->LIsta_vis_articoli->item(i)->text()){
            idx = i;         }
    }
      Articolo* x = articoli_gest.at(idx);
      QStringList a = x->getKeywords();
      foreach(QString s, a){
         ui->Lista_vis_keyword->addItem(s);
      }
    ui->LIsta_vis_articoli->clearSelection();
}



void Gestore::on_Bottone_vis_artEconf_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->visual_conf_riv);
}

void Gestore::on_Bottone_vis_confEart_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->visual_conf_riv);
}

void Gestore::on_tornamenu_11_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Aggiungi_2_clicked()
{
  QStringList ord;
 if(ui->radio_No_filtro->isChecked() == true && ui->radio_filtrati->isChecked() == false ){
  ui->lista_articoli_keyword->clear();
  QString k = ui->InserisciKeyword->toPlainText();
  int cont = -1;
   for(auto it = articoli_gest.begin(); it != articoli_gest.end();++it){
      cont++;
     QList<QString> list = (**it).getKeywords();
       for(auto ite = list.begin(); ite != list.end();++ite){
            if((*ite) == k){
              ui->lista_articoli_keyword->addItem(ui->LIsta_vis_articoli->item(cont)->text());
            }
       }
   }
   return;
 }
  if(ui->radio_No_filtro->isChecked() == false && ui->radio_filtrati->isChecked() == true ){
      ui->lista_articoli_keyword->clear();
      QString k = ui->InserisciKeyword->toPlainText();
      int cont = -1;
       for(auto it = articoli_gest.begin(); it != articoli_gest.end();++it){
          cont++;
         QList<QString> list = (**it).getKeywords();
           for(auto ite = list.begin(); ite != list.end();++ite){
                if((*ite) == k){
                  ord.push_back(ui->LIsta_vis_articoli->item(cont)->text());
                }
           }
       }
     ordinaArticoloAnnoDec(ord);
     return;
  }


}

void Gestore::ordinaArticoloAnnoDec(QStringList a)
{
 QVector<QString> articoli;
 QVector<QString> date;
 QVector<float> prezzi;
 QVector<QString> autori;
  for(auto l= a.begin(); l != a.end();++l){
    for(int i = 0; i < ui->LIsta_vis_articoli->count(); i++){
      if(ui->LIsta_vis_articoli->item(i)->text() == (*l)){
        if(a.size() == 1){
           ui->LIsta_vis_articoli->item(i)->text();
           return;
        }
            date.push_back(articoli_gest.at(i)->getAnno());
            articoli.push_back(ui->LIsta_vis_articoli->item(i)->text());
            prezzi.push_back(articoli_gest.at(i)->getPrezzo());
            autori.push_back(articoli_gest.at(i)->getPrimoAutore());
      }
    }
  }


bool swap = false;
 while(!swap){
   swap = true;
    for(int i = 0; i < articoli.size()-1; i++){
      if(date[i] < date[i+1] ){
       articoli.swapItemsAt(i,i+1);
       date.swapItemsAt(i,i+1);
       swap = false;
       break;
      }
           if(date[i] == date[i+1]){
              if(prezzi[i] > prezzi[i+1] ){
               articoli.swapItemsAt(i,i+1);
               date.swapItemsAt(i,i+1);
               prezzi.swapItemsAt(i,i+1);
               swap = false;
               break;
              }
           }
             if(date[i] == date[i+1]){
                if(prezzi[i] == prezzi[i+1] ){
                  if(autori[i] > autori[i+1] ){
                      articoli.swapItemsAt(i,i+1);
                      date.swapItemsAt(i,i+1);
                      prezzi.swapItemsAt(i,i+1);
                      autori.swapItemsAt(i,i+1);
                      swap = false;
                      break;
                  }
               }
             }
   }
 }

  for(int i = 0; i < articoli.size();i++){
    ui->lista_articoli_keyword->addItem(articoli[i]);
  }

}


void Gestore::on_pushButton_2_clicked()
{
    ui->Lista_vis_keyword_guadagno->clear();
    QVector<QString> listk;
    QVector<double> lista_prezzi;
    double zero = 0.0;
    double max = 0;
    QString prezzo;
    QString sp = "  ";
     for(auto it = articoli_gest.begin(); it != articoli_gest.end(); ++it){
         QStringList lista = (*it)->getKeywords();
         foreach (QString k, lista) {
           if(!listk.contains(k)){
             listk.push_back(k);
             lista_prezzi.push_back(zero);
           }
         }
     }

     for(int i=0;i < listk.size(); i++){
        for(auto itk = articoli_gest.begin(); itk != articoli_gest.end(); ++itk){
            if((*itk)->keywordPresente(listk[i])){
               lista_prezzi[i] += (*itk)->getPrezzo();
            }
        }
     }

     for(int i=0;i < lista_prezzi.size(); i++){
       if(lista_prezzi[i] > max){
          max = lista_prezzi[i];
       }
     }


     for(int i=0;i < lista_prezzi.size(); i++){
        if(lista_prezzi[i] == max){
           ui->Lista_vis_keyword_guadagno->addItem(listk[i] += (sp + "€" +(prezzo = QString::number(lista_prezzi[i]))));
        }
     }
}


void Gestore::on_radio_Anno_crescente_clicked()
{
  ui->radio_Nessun_filtro->setChecked(false);
}

void Gestore::on_radio_Nessun_filtro_clicked()
{
  ui->radio_Anno_crescente->setChecked(false);
}

void Gestore::on_Bottone_Add_COnferenza_3_clicked()
{
 ui->stackedWidget->setCurrentWidget(ui->pagina_vis_guadagno);

}

void Gestore::on_pushButton_3_clicked()
{
 QString c = ui->TestoNome_conferenza->toPlainText();
 QString a = ui->TestoAnno_conf->toPlainText();
 ui->TestoNome_conferenza->clear();
 ui->TestoAnno_conf->clear();
 double prezzo = 0.0;
 bool trovato = false;

 if( c.isEmpty() || a.isEmpty()){
     QMessageBox mess(QMessageBox::Critical,"Errore","I campi: Nome e Anno non possono essere vuoti", QMessageBox::Ok,this);
     mess.exec();
     return;
 }

     for(auto it = elenco_pubbl.begin(); it != elenco_pubbl.end(); ++it){
       if((*it)->getNome() == c && (*it)->getAnno() == a){
           trovato = true;
             QList<Articolo*> list = (*it)->getListArt();
               for(auto ite = list.begin(); ite != list.end(); ++ite){
                prezzo += (*ite)->getPrezzo();
               }
       }
     }

 if(!trovato){
     QMessageBox mess(QMessageBox::Critical,"Errore","La ricerca non ha trovato nussun risultato", QMessageBox::Ok,this);
     mess.exec();
     return;
 }
 ui->lcdprezzo_conf->display(prezzo);
}

void Gestore::on_tornamenu_12_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Bottone_Add_Rivista_3_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_vis_riv_auto_no_pubb);
}

void Gestore::on_tornamenu_13_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}

void Gestore::on_Lista_autori_rivpub_itemClicked(QListWidgetItem *item)
{
   ui->Lista_conf_riv->clear();
    int idx = 0;
    bool trovato = false;
    int cont = 0;
       for(int i=0;i < ui->lista_vis_autori->count();i++){
          if(item->text() == ui->lista_vis_autori->item(i)->text()){
             idx = i;
          }
       }

   for(auto it = elenco_pubbl.begin(); it != elenco_pubbl.end(); ++it){
     trovato = false;
       if((*it)->getPubblicazione() ==  false){
         QList<Articolo*> a = (*it)->getArticoli();
           for(auto art = a.begin(); art != a.end(); ++art){
              QList<Autore*> aut =(*art)->getAutori();
                for(auto i = aut.begin(); i != aut.end(); ++i){
                  if((*i)->getId() ==  autori_gest.at(idx)->getId()){
                   trovato = true;
                  }
                }
           }
      }

      if(!trovato){
       ui->lista_riv_nopubb->addItem(ui->Lista_conf_riv->item(cont)->text());
      }
    cont++;
   }

}

void Gestore::on_tornamenu_14_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_menu);
}


void Gestore::on_Bottone_Add_Rivista_4_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagina_vis_riv_specifiche);
  ui->Lista_riv_specifiche->clear();

  QVector<QString> ki;
  QVector<QString> kj;


  for(int i = 0; i < elenco_pubbl.size(); i++){
    for(int j = 0; j < elenco_pubbl.size(); j++){
      if(i!=j){
        if((elenco_pubbl[j])->getPubblicazione() == false && elenco_pubbl[i]->getPubblicazione() == false){         
           QList<Articolo*> artj = (elenco_pubbl[j])->getArticoli();
           QList<Articolo*> arti = (elenco_pubbl[i])->getArticoli();
            for(auto a = arti.begin(); a != arti.end(); ++a){
               QStringList key1 = ((*a)->getKeywords());
               ki.clear();
               foreach(QString s, key1){
                  ki.push_back(s);
               }
            }
            for(auto a = artj.begin(); a != artj.end(); ++a){
               QStringList key2 = ((*a)->getKeywords());
               kj.clear();
               foreach(QString s, key2){
                  kj.push_back(s);
               }
            }
            if(controlloKeywords(ki,kj) == true){
               ui->Lista_riv_specifiche->addItem(ui->Lista_conf_riv->item(i)->text());
           }
       }
     }
   }
 }

 clean();

}


bool Gestore::controlloKeywords(QVector<QString> ki,QVector<QString> kj)
{
 bool trovato = true;
  for(int i=0; i< ki.size();i++){
      for(int j=0; j< kj.size();j++){
         trovato = false;
          if(ki[i] == kj[j]){    
              kj[j] = "__";
              trovato = true;
          }
          if(trovato){
              break;
          }
      }
    if(!trovato){
      return false;
    }
  }
 return true; 

}

void Gestore::clean(){

  for(int i = 0 ; i < ui->Lista_riv_specifiche->count(); i++){
      for(int j = 0 ; j < ui->Lista_riv_specifiche->count(); j++){
          if(ui->Lista_riv_specifiche->item(i)->text() ==  ui->Lista_riv_specifiche->item(j)->text()){
              delete ui->Lista_riv_specifiche->item(i);
          }
      }
  }
}
