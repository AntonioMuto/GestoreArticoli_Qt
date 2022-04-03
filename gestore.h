#ifndef GESTORE_H
#define GESTORE_H

#include <QMainWindow>
#include <QListWidget>
#include "Articolo.h"
#include "Autore.h"
#include "Conferenza.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gestore; }
QT_END_NAMESPACE

class Gestore : public QMainWindow
{
    Q_OBJECT

public:
    Gestore(QWidget *parent = nullptr);
    ~Gestore();

private slots:

    void on_Bottone_autore_clicked();

    void on_Bottone_conferenza_clicked();

    void on_Bottone_rivista_clicked();

    void on_Bottone_articolo_clicked();

    void on_Aggiungi_clicked();

    void on_Bottone_Add_Autore_clicked();

    void on_tornamenu_clicked();

    void on_tornamenu_2_clicked();

    void on_tornamenu2_clicked();

    void on_tornamenu3_clicked();

    void on_tornamenu4_clicked();

    void on_tornamenu_3_clicked();

    void on_Bottone_Add_Articolo_clicked();

    void on_Bottone_Add_COnferenza_clicked();

    void on_tornamenu_Addconf_clicked();

    void on_tornamenu_4_clicked();

    void on_Bottone_Add_Rivista_clicked();

    void on_Elimina_list_clicked();

    void on_Elimina_Articoli_clicked();

    void on_tornamenu_5_clicked();

    void on_Bottone_inserisci_Autore_2_clicked();

    void on_AggiungiAutore_2_clicked();

    void on_Elimina_Autori_2_clicked();

    void on_pushButton_clicked();

    void on_tornamenu_6_clicked();

    void on_tornamenu_7_clicked();

    void on_Bottone_Add_Autore_2_clicked();

    void on_lista_vis_autori_itemClicked(QListWidgetItem *item);

    void on_Bottone_Aggiungi_conf_clicked();

    void on_Bottone_Pub_Articolo_clicked();

    void on_Pubblica_clicked();

    void on_Bottone_Aggiungi_Rivista_clicked();

    void on_tornamenu_8_clicked();

    void on_Bottone_Add_Rivista_2_clicked();

    void on_Lista_vis_Conferenza_itemClicked(QListWidgetItem *item);

    void on_Bottone_Add_COnferenza_2_clicked();

    void on_tornamenu_Addconf_2_clicked();

    void on_tornamenu_9_clicked();

    void on_tornamenu_10_clicked();

    void on_Bottone_Pub_Articolo_3_clicked();

    void on_LIsta_vis_articoli_itemClicked(QListWidgetItem *item);

    void on_Bottone_vis_artEconf_clicked();

    void on_Bottone_vis_confEart_clicked();

    void on_tornamenu_11_clicked();

    void on_Aggiungi_2_clicked();

    void on_pushButton_2_clicked();

    void on_radio_Anno_crescente_clicked();

    void on_radio_Nessun_filtro_clicked();

    void on_Bottone_Add_COnferenza_3_clicked();

    void on_pushButton_3_clicked();

    void on_tornamenu_12_clicked();

    void on_Bottone_Add_Rivista_3_clicked();

    void on_tornamenu_13_clicked();

    void on_Lista_autori_rivpub_itemClicked(QListWidgetItem *item);

    void on_tornamenu_14_clicked();

    void on_Bottone_Add_Rivista_4_clicked();

public slots:

    int getIndex(QListWidgetItem*, QListWidget*);

    QListWidgetItem* getItem(QListWidget*);

    QString on_calendarWidget_clicked();

    QString on_data_riv_clicked();

    void ordinaArticoloAnnoCre(QStringList a);

    void ordinaArticoloAnnoDec(QStringList a);

    bool controlloKeywords(QVector<QString> ki,QVector<QString> kj);

    void clean();

private:
    Ui::Gestore *ui;
    QList<Autore*> autori_gest;
    QList<Articolo*> articoli_gest;
    QList<Pubblicazione*> elenco_pubbl;
};
#endif // GESTORE_H
