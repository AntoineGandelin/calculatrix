#include "fenetre.h"
#include "ui_fenetre.h"
#include "string"
#include "iostream"
using std::stof;

fenetre::fenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fenetre)
{
    ui->setupUi(this);
}

fenetre::~fenetre()
{
    delete ui;
}

void fenetre::on_pushButton0_clicked()
{
    resultat = resultat + "0";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton1_clicked()
{
    resultat = resultat + "1";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton2_clicked()
{
    resultat = resultat + "2";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton3_clicked()
{
    resultat = resultat + "3";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton4_clicked()
{
    resultat = resultat + "4";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton5_clicked()
{
    resultat = resultat + "5";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton6_clicked()
{
    resultat = resultat + "6";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton7_clicked()
{
    resultat = resultat + "7";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton8_clicked()
{
    resultat = resultat + "8";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_pushButton9_clicked()
{
    resultat = resultat + "9";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_point_clicked()
{
    resultat = resultat + ".";
    ui->detail_calcul->setText(resultat.c_str());;
}

void fenetre::on_plus_clicked()
{
    resultat = resultat + " + ";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_moins_clicked()
{
    resultat = resultat + " - ";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_fois_clicked()
{
    resultat = resultat + " X ";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_slash_clicked()
{
    resultat = resultat + " / ";
    ui->detail_calcul->setText(resultat.c_str());
}

void fenetre::on_egal_clicked()
{
    resultat = resultat + " ";
    int i = 0;
    std::string s = "";
    while(resultat[i])
        {
        if(resultat[i] != ' ')
            {
            s = s + resultat[i];
            }
        else
            {
            calcul.push_back(s);
            s = "";
            }
        i++;
        }

int taille = calcul.size();
for (int i = 0; i < taille ; i++)
    {
    if(calcul.at(i) == "X" or calcul.at(i) == "/" )
        {
        if(calcul[i] == "X")
            {
            float mult = 0;
            mult = stof(calcul.at(i-1)) * stof(calcul.at(i+1));
            std::string res(std::to_string(mult));
            calcul.at(i-1) = res;
            for (int j = i; j < taille - 2; j++)
                {
                calcul.at(j) = calcul.at(j+2);
                }
            calcul.pop_back();
            calcul.pop_back();
            i--;
            taille = calcul.size();
            }
        if(calcul[i] == "/")
            {
            float div = 0;
            div = stof(calcul.at(i-1)) / stof(calcul.at(i+1));
            std::string res(std::to_string(div));
            calcul.at(i-1) = res;
            for (int j = i; j < taille - 2; j++)
                {
                calcul.at(j) = calcul.at(j+2);
                }
            calcul.pop_back();
            calcul.pop_back();
            i--;
            taille = calcul.size();
            }
         }
    }
for(int i = 0; i < taille; i++)
    {
    if(calcul.at(i) == "+" or calcul.at(i) == "-")
        {
        if(calcul[i] == "+")
            {
            float add = 0;
            add = stof(calcul.at(i-1)) + stof(calcul.at(i+1));
            std::string res(std::to_string(add));
            calcul.at(i-1) = res;
            for (int j = i; j < taille - 2; j++)
                {
                calcul.at(j) = calcul.at(j+2);
                }
            calcul.pop_back();
            calcul.pop_back();
            i--;
            taille= calcul.size();
            }
        if(calcul[i] == "-")
            {
            float sous = 0;
            sous = stof(calcul.at(i-1)) - stof(calcul.at(i+1));
            std::string res(std::to_string(sous));
            calcul.at(i-1) = res;
            for (int j = i; j < taille-2; j++)
                {
                calcul.at(j) = calcul.at(j+2);
                }
            calcul.pop_back();
            calcul.pop_back();
            i--;
            taille = calcul.size();
            }
        }
    }
ui->resultat->setText(calcul.at(0).c_str());
calcul.clear();
resultat = "";
}

void fenetre::on_resultat_released()
{
    resultat = resultat + ".";
    ui->resultat->setText(resultat.c_str());
}
