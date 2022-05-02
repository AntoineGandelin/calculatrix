#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include "vector"
#include "string"

QT_BEGIN_NAMESPACE
namespace Ui { class fenetre; }
QT_END_NAMESPACE

class fenetre : public QMainWindow
{
    Q_OBJECT

public:
    fenetre(QWidget *parent = nullptr);
    ~fenetre();

private slots:
    void on_pushButton0_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();
    void on_point_clicked();
    void on_egal_clicked();
    void on_plus_clicked();
    void on_moins_clicked();
    void on_fois_clicked();
    void on_slash_clicked();
    void on_resultat_released();

private:
    std::string resultat;
    std::vector <std::string> calcul;
    Ui::fenetre *ui;
};
#endif // FENETRE_H
