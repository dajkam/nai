#include <iostream>
#include <cmath>
#include <vector>
#include<string>
#include<random>
#include<cstdlib>
#include<ctime>
#include <algorithm>
#include <functional>
//2♠, 2♣, 2♥, 2♦

using namespace std;


class karta {

public:
string kolor;
string f;
int starszenstwo;
bool atu;
bool zagrana;
int w;
int pun;
char lit;
string czyja;



karta();
karta(int starszenstwo, int w);



};

class gracz {

public:


    vector<karta> reka =vector<karta> (13);
    vector<karta> reka_zurzyte{ vector<karta> (13)};




    vector<karta> trefl;
    vector<karta> caro;
    vector<karta> kier;
    vector<karta> pik;


    string pozycja;
    int kolejnosc;

    int punkty;

    gracz();

    gracz(vector < karta >& reka, string pozycja);




  //  void sortuj();

};


class para {
public:
  gracz g1;
  gracz g2;
  int wziete;
  int oddane;
  int punkty;
  string nazwa;

  int dtrefl;
  int dcaro;
  int dkier;
  int dpik;

  bool rozgrywajaca;

  para();

  para(gracz g1,gracz g2, string nazwa);


};


class licytacja {
public:

  para NS;
  para WE;

  gracz N;
  gracz S;
  gracz W;
  gracz E;

  string atu;
  int kontrakt;
  para rozgrywajaca_para;
  gracz rozgrywajacy_gracz;
  gracz dziadek;
  gracz zaczynajacy_licytacje; // nie istotne
  gracz wistujacy;
  int pozostale_ruchy;
  int nr_konstruktora;

  licytacja();


  // automatyczna licytacja

  licytacja(para NS,para WE, gracz N, gracz S, gracz W, gracz E,int nr_konstruktora);


  // ręczna licytacja
  licytacja(para NS,para WE, gracz N, gracz S, gracz W, gracz E,int nr_konstruktora, gracz zaczynajacy_licytacje);


};



gracz :: gracz(){}
para :: para(){}
karta :: karta(){ kolor = "nic"; f = "nic";}
licytacja :: licytacja(){}

// licytacja automatyczna

licytacja :: licytacja(para NS_,para WE_, gracz N_, gracz S_, gracz W_, gracz E_,int nr_konstruktora_)
: NS(NS_)
, WE(WE_)
, N(N_)
, S(S_)
, W(W_)
, E(E_)
, nr_konstruktora(nr_konstruktora_)
{

pozostale_ruchy=13;
kontrakt =0;
  atu="atu nie zostało jeszcze wybrane";
  //rozgrywajaca_para;
  //rozgrywajacy_gracz;
  //dziadek;

  if (nr_konstruktora!=1) {
    cout << "wybrałeś zły konstruktor zresetuj program" << "\n";
  }

  if (NS.punkty>WE.punkty) {
    NS.rozgrywajaca=true;
    rozgrywajaca_para=NS;
  }
  if (WE.punkty>NS.punkty) {
    WE.rozgrywajaca=true;
    rozgrywajaca_para=WE;
  }
  if (NS.punkty==WE.punkty) {
    std::cout << "zrównoważony podział punktów zresetój program" << '\n';
  }

  //NS

  if (NS.rozgrywajaca==true) {
    int t=0;
    t = max(max(NS.dtrefl,NS.dcaro),max(NS.dkier,NS.dpik));
    std::cout << "t === " << t << '\n';

    if (t==NS.dtrefl) {
      atu="♣";
    }
    if (t==NS.dcaro) {
      atu="♦";
    }
    if (t==NS.dkier) {
      atu="♥";
    }
    if (t==NS.dpik) {
      atu="♠";
    }
    std::cout << "atu :::" << atu << '\n';

    if (N.punkty>=S.punkty) {
      rozgrywajacy_gracz=N;
      dziadek=S;
      wistujacy=E;  //tak żeby rozgrywający był ostatni
    }

    if (S.punkty>N.punkty) {
      rozgrywajacy_gracz=S;
      dziadek=N;
      wistujacy=W;
    }
    kontrakt=t-6;

    std::cout << "kontrakt to :::" << kontrakt<< atu << '\n';
  }

    //WE


if (WE.rozgrywajaca==true) {
    int t=0;
    t = max(max(WE.dtrefl,WE.dcaro),max(WE.dkier,WE.dpik));
    std::cout << "t === " << t << '\n';

    if (t==WE.dtrefl) {
      atu="♣";
    }
    if (t==WE.dcaro) {
      atu="♦";
    }
    if (t==WE.dkier) {
      atu="♥";
    }
    if (t==WE.dpik) {
      atu="♠";
    }
    std::cout << "atu :::" << atu << '\n';

    if (W.punkty>=E.punkty) {
      rozgrywajacy_gracz=W;
      dziadek=E;
      wistujacy=N;  //tak żeby rozgrywający był ostatni
    }

    if (E.punkty>W.punkty) {
      rozgrywajacy_gracz=E;
      dziadek=W;
      wistujacy=S;
    }

      kontrakt=t-6;

      std::cout << "kontrakt to :::" << kontrakt<< atu << '\n';
  }

  if (atu == "♣") {
    for (int i = 0; i < N.trefl.size(); i++) {
      N.trefl[i].atu = true;      }

    for (int i = 0; i < S.trefl.size(); i++) {
      S.trefl[i].atu = true;      }

    for (int i = 0; i < W.trefl.size(); i++) {
      W.trefl[i].atu = true;      }

    for (int i = 0; i < E.trefl.size(); i++) {
      E.trefl[i].atu = true;      }
  }

  if (atu == "♦") {
    for (int i = 0; i < N.caro.size(); i++) {
      N.caro[i].atu = true;      }

    for (int i = 0; i < S.caro.size(); i++) {
      S.caro[i].atu = true;      }

    for (int i = 0; i < W.caro.size(); i++) {
      W.caro[i].atu = true;      }

    for (int i = 0; i < E.caro.size(); i++) {
      E.caro[i].atu = true;      }
  }

  if (atu == "♥") {
    for (int i = 0; i < N.kier.size(); i++) {
      N.kier[i].atu = true;      }

    for (int i = 0; i < S.kier.size(); i++) {
      S.kier[i].atu = true;      }

    for (int i = 0; i < W.kier.size(); i++) {
      W.kier[i].atu = true;      }

    for (int i = 0; i < E.kier.size(); i++) {
      E.kier[i].atu = true;      }
  }

  if (atu == "♠") {
    for (int i = 0; i < N.pik.size(); i++) {
      N.pik[i].atu = true;      }

    for (int i = 0; i < S.pik.size(); i++) {
      S.pik[i].atu = true;      }

    for (int i = 0; i < W.pik.size(); i++) {
      W.pik[i].atu = true;      }

    for (int i = 0; i < E.pik.size(); i++) {
      E.pik[i].atu = true;      }
  }










}

// licytacja ręczna

licytacja :: licytacja(para NS_,para WE_, gracz N_, gracz S_, gracz W_, gracz E_,int nr_konstruktora_, gracz zaczynajacy_licytacje_)
: NS(NS_)
, WE(WE_)
, N(N_)
, S(S_)
, W(W_)
, E(E_)
, nr_konstruktora(nr_konstruktora_)
, zaczynajacy_licytacje(zaczynajacy_licytacje_)


{
  pozostale_ruchy=13;
  atu="atu nie zostało jeszcze wybrane";
  //rozgrywajaca_para;
  //rozgrywajacy_gracz;
  //dziadek;
  //nr_konstruktora;
  //zaczynajacy_licytacje;
  if (nr_konstruktora!=2) {
    cout << "wybrałeś zły konstruktor zresetuj program" << "\n";
  }
  bool p = true;
  int pass=0;
  std::cout << "wpisz wysokość kontraktu i kolor słownie atu bez odstępów lub słowo pass 4 pasy pominą rozdanie a 3 pasy zakończą licytację " << '\n';
  int w;
  string k;
  while (p) {
    //N
    getline (std::cin,k);
    if (k=="pass") {
      pass++;
    }
    else{
      int n;
      pass=0;
      n=k[0]-30;
      atu=k[1];
      std::cout << "kon to  " << k << '\n';


    }

    //E

    getline (std::cin,k);
    if (k=="pass") {
      pass++;
    }
    else{
      int n;
      pass=0;
      n=k[0]-30;
      atu=k[1];
      std::cout << "kon to  " << k << '\n';


    }

    //S

    getline (std::cin,k);
    if (k=="pass") {
      pass++;
    }
    else{
      int n;
      pass=0;
      n=k[0]-30;
      atu=k[1];
      std::cout << "kon to  " << k << '\n';


    }

    //W

    getline (std::cin,k);
    if (k=="pass") {
      pass++;
    }
    else{
      int n;
      pass=0;
      n=k[0]-30;
      atu=k[1];
      std::cout << "kon to  " << k << '\n';


    }





    if (pass >=4) {
      p=false;
      break;
    }
  }


/*

NALEŻY DOKONCZYĆ

*/

}









gracz :: gracz(vector < karta >& reka_,string pozycja_)
: reka(reka_)
, pozycja(pozycja_)
{

  punkty=0;

  for (int i = 0; i < reka.size(); i++) {
    punkty=punkty+reka[i].pun;
  }




}

para :: para(gracz g1_, gracz g2_,string nazwa_)
:  g1(g1_)
,  g2(g2_)
,  nazwa(nazwa_)

{
  rozgrywajaca=0;
  wziete=0;
  oddane=0;
  punkty=g1_.punkty+g2_.punkty;

  dtrefl=g1_.trefl.size()+g2_.trefl.size();
  dcaro=g1_.caro.size()+g2_.caro.size();
  dkier=g1_.kier.size()+g2_.kier.size();
  dpik=g1_.pik.size()+g2_.pik.size();
}

void  sortuj(gracz &g){
    //std::cout << g.reka.size() << '\n';
  for (int i = 0; i < g.reka.size(); i++) {
      //std::cout << g.reka.size() << '\n';
      //std::cout << " " << g.reka[i].f<< g.reka[i].kolor<< '\n';
      //std::cout << "/* message */" << '\n';
      //std::cout << "" << '\n';


      if (g.pozycja=="N") {
        g.reka[i].czyja="N";
      }
      if (g.pozycja=="S") {
        g.reka[i].czyja="S";
      }
      if (g.pozycja=="W") {
        g.reka[i].czyja="W";
      }
      if (g.pozycja=="E") {
        g.reka[i].czyja="E";
      }



    if (g.reka[i].kolor=="♣") {
      g.trefl.push_back(g.reka[i]);
      //std::cout << " " << g.reka[i].f<< g.reka[i].kolor<< '\n';
      //std::cout << g.pik.back().f<<g.pik.back().kolor << ' ';
    }
    if (g.reka[i].kolor=="♦") {
      g.caro.push_back(g.reka[i]);
      //std::cout << " " << g.reka[i].f<< g.reka[i].kolor<< '\n';
      //std::cout << g.caro.back().f << g.caro.back().kolor<<' ';
    }
    if (g.reka[i].kolor=="♥") {
      g.kier.push_back(g.reka[i]);
      //std::cout << " " << g.reka[i].f<< g.reka[i].kolor<< '\n';
      //std::cout << g.kier.back().f << g.kier.back().kolor<< ' ';
    }
    if (g.reka[i].kolor=="♠") {
      g.pik.push_back(g.reka[i]);
    //  std::cout << " " << g.reka[i].f<< g.reka[i].kolor<< '\n';
  //  std::cout << g.pik.back().f << g.pik.back().kolor<< ' ';
    }
  }
  }

void segreguj(gracz &g){
  for (int i = 0; i < g.trefl.size(); i++) {
    if (g.trefl[i].w>g.trefl[i+1].w) {
    swap(g.trefl[i],g.trefl[i+1]);
    }
  }

  for (int i = 0; i < g.caro.size(); i++) {
    if (g.caro[i].w>g.caro[i+1].w) {
    swap(g.caro[i],g.caro[i+1]);
  }
 }

    for (int i = 0; i < g.kier.size(); i++) {
      if (g.kier[i].w>g.kier[i+1].w) {
      swap(g.kier[i],g.kier[i+1]);
      }
    }
    for (int i = 0; i < g.pik.size(); i++) {
      if (g.pik[i].w>g.pik[i+1].w) {
      swap(g.pik[i],g.pik[i+1]);
      }
    }

  }















karta :: karta(int starszenstwo_,int w_)
: starszenstwo(starszenstwo_)
, w(w_)
{
if(starszenstwo_==0){
  kolor="♣";
  lit='t';
}

if(starszenstwo_==1){
  kolor = "♦";
  lit='c';
}

if(starszenstwo_==2){
    kolor="♥";
    lit='k';
}

if(starszenstwo_==3){
    kolor = "♠";
    lit='p';
}


pun=0;

if (w_==0) {
  f="2";
  /* code */
}
if (w_==1) {
  f="3";
  /* code */
}

if (w_==2) {
  f="4";
  /* code */
}

if (w_==3) {
  f="5";
  /* code */
}

if (w_==4) {
  f="6";
  /* code */
}

if (w_==5) {
  f="7";
  /* code */
}
if (w_==6) {
  f="8";
  /* code */
}

if (w_==7) {
  f="9";
  /* code */
}
if (w_==8) {
  f="10";
  /* code */
}
if (w_==9) {
  f="J";
  pun=1;
  /* code */
}
if (w_==10) {
  f="Q";
  pun=2;
  /* code */
}
if (w_==11) {
  f="K";
  pun=3;
  /* code */
}
if (w_==12) {
  f="A";
  pun=4;
  /* code */
}

std::cout << "w tworzonej karty " << w << '\n';







zagrana=0;
atu=0;



}

 void tworztalie(vector < karta >& talia){
  for (int i=0;i < 4; i++) {


    for (int j = 0; j < 13; j++) {


      talia[j+13*i]=karta(i,j);
      std::cout << "wartosc karty tworzonej::::::   "<< talia[j+13*i].w << '\n';
      /*
            WYMUS ABY W ZNOWU REPREZONTOWAŁO RZECZYWISTĄ WARTOSC KARTY
      */


    }

  }







}







void wyswietl(vector < karta >& talia){
  std::cout << "" << '\n';
  std::cout << "" << '\n';
  std::cout << "" << '\n';


 for (int i=0;i < 4; i++) {


   for (int j = 0; j < 13; j++) {



     std::cout << talia[j+i*13].f << ""<< talia[j+i*13].kolor ;





   }

std::cout << "" << '\n';
std::cout << "" << '\n';
std::cout << "" << '\n';


 }







}
void wyswietl_kolor(vector < karta >& kolor) {
  for (int i = 0; i < kolor.size(); i++) {
    std::cout << kolor[i].f <<kolor[i].kolor << " wartosc karty  " << kolor[i].w << '\n';
  }
  if (kolor.empty()) {
  std::cout << "nie ma koloru" << '\n';
  }

  std::cout << "" << '\n';
  std::cout << "" << '\n';
  std::cout << "" << '\n';
}

int myrandom (int i) { return std::rand()%i;}
void tasuj(vector < karta >& talia) {
  random_shuffle(talia.begin(),talia.end(),myrandom);

}
void rozdaj(vector<karta> &reka1,vector<karta> &reka2,vector<karta> &reka3,vector<karta> &reka4,vector<karta> &talia){
  int i=0;

while (talia.size()>0) {
  //std::cout << talia.size() << '\n';
  reka1.push_back(talia.back());
  talia.pop_back();

    //std::cout << talia.size() << '\n';
  reka2.push_back(talia.back());
  talia.pop_back();

    //std::cout << talia.size() << '\n';
  reka3.push_back(talia.back());
  talia.pop_back();

    //std::cout << talia.size() << '\n';
  reka4.push_back(talia.back());
  talia.pop_back();

  //  std::cout << talia.size() << '\n';
  i++;


}


}


void wyswietl_reke(vector<karta> &reka) {
  for (int i = 0; i < reka.size(); i++) {
    std::cout << reka[i].f << " "<<reka[i].kolor << "  ";
    if (i%3==0) {

      std::cout << "     " << '\n';
    }
  }
  std::cout  << '\n';
  std::cout << '\n';
  std::cout  << '\n';
}

void tworz_graczy(vector<karta> &reka1,vector<karta> &reka2,vector<karta> &reka3,vector<karta> &reka4,
  gracz &N,gracz &S,gracz &W,gracz &E){

//gracz(vector < karta >& reka,string pozycja)


  N = gracz(reka1,"N");
  S = gracz(reka2,"S");
  W = gracz(reka3, "W");
  E = gracz(reka4, "E");

  //para(gracz g1, gracz g2,string nazwa)




}
void przygotowanie(para &NS,para &WE) {
  if (NS.punkty==WE.punkty) {
    std::cout << "rowny rozkład punktów uruchom program ponownie" << '\n';

  }
  if (NS.punkty>WE.punkty) {
    NS.rozgrywajaca=1;
  }
  else{
    WE.rozgrywajaca=1;

  }
  if (NS.rozgrywajaca==1) {
    /* code */
  }
  if (WE.rozgrywajaca==1) {
    /* code */
  }
}

int war(string &r){
  char l;
  int n;
  l=r[0];
  n=(int)(l-50);
  if (n==(-1)) {
    n=8;
  }
  if (l=='A'||l=='K'||l=='Q'||l=='J') {
    if (l=='J') {
      n=9;
    }
    if (l=='Q') {
      n=10;
    }
    if (l=='K') {
      n=11;
    }
    if (l=='A') {
      n=12;
    }
  }
  std::cout << "l i n " << l << "  "<< n << '\n';
  return n;
}
string kol(string &r){
  //2♠, 2♣, 2♥, 2♦
  string k;
  if (r[1]=='t') {
    k = "♣" ;
  }
  if (r[1]=='c') {
    k = "♦" ;
  }
  if (r[1]=='k') {
    k = "♥" ;
  }
  if (r[1]=='p') {
    k = "♠" ;
  }

  return  k;
}

karta znajdz2(vector < karta >& kolor, int n){
  karta card;
  for (int i = 0; i < kolor.size(); i++) {

    if (kolor[i].w==n) {
      card=kolor[i];
      kolor.erase(kolor.begin()+i);
      std::cout << "karta ::  " <<  card.kolor << card.f<< '\n';
      break;

    }
      if (card.kolor == "nic" && card.f == "nic") {
    std::cout << "nie masz karty o podanej figurze w danym kolorze" << '\n';
  }
}

  return card;
  /*

ZAPROGRAMUJ CO NA WYPADEK NIE ZNALEZIENIA KARTY U GRACZA CZYLI PO PROSKU JEJ NIE MA

  */

}

karta znajdz(gracz &g, int n, string k, bool &tr,bool &ca,bool &ki,bool &pi){
  karta card;
  if (!g.trefl.empty()) {
    if (k=="♣") {
    card =  znajdz2(g.trefl,n);
    if (g.trefl.empty()) {
      tr = 1;
    }
    }
  }else{std::cout << "nie masz żadnych trefli" << '\n';}
  if (!g.caro.empty()) {
    if (k=="♦") {
      card = znajdz2(g.caro,n);
      if (g.caro.empty()) {
        ca=1;
      }
    }
  }else{std::cout << "nie masz żadnych caro" << '\n';}
  if (!g.kier.empty()) {
    if (k=="♥") {
      card = znajdz2(g.kier,n);
      if (g.kier.empty()) {
        ki = 1;
      }
  }
}else{std::cout << "nie masz żadnych kierów" << '\n';}
if (!g.pik.empty()) {
  if (k=="♠") {
  card =  znajdz2(g.pik,n);
  if (g.pik.empty()) {
    pi =1;
  }
  }
}else{std::cout << "nie masz żadnych pików" << '\n';}



  return card;

}
void wyswietl_kolory_graczy2(gracz &g) {
  std::cout << "  trefl :  " ;
  for (int i = 0; i < g.trefl.size(); i++) {
    std::cout << g.trefl[i].f << g.trefl[i].kolor<< "  "; // 2- wie spacje

  }

  std::cout << "  caro :  " ;
  for (int i = 0; i < g.caro.size(); i++) {
    std::cout << g.caro[i].f << g.caro[i].kolor<< "  ";

  }

  std::cout << "  kier :  " ;
  for (int i = 0; i < g.kier.size(); i++) {
    std::cout << g.kier[i].f << g.kier[i].kolor<< "  ";

  }
  std::cout << "  pik :  " ;
  for (int i = 0; i < g.pik.size(); i++) {
    std::cout << g.pik[i].f << g.pik[i].kolor<< "  ";

  }


}
  void wyswietl_kolory_graczy(gracz tab[], int &i){
      //0
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      if (i == 0) {
        cout << "\033[30;47m" ;
      }
      std::cout << tab[0].pozycja<< " :  " ;// 2 spacje
      wyswietl_kolory_graczy2(tab[0]);
      cout << "\033[0m" ;
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';


      //1
      if (i == 1) {
        cout << "\033[30;47m" ;
      }
      std::cout << tab[1].pozycja<< " :  " ;// 2 spacje
      wyswietl_kolory_graczy2(tab[1]);
      cout << "\033[0m" ;
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';

      //3
      if (i == 3) {
        cout << "\033[30;47m" ;
      }

      std::cout << tab[3].pozycja<< " :  " ;// 2 spacje
      wyswietl_kolory_graczy2(tab[3]);
      cout << "\033[0m" ;
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';


      if (i == 2) {
        cout << "\033[30;47m" ;
      }
      std::cout << tab[2].pozycja<< " :  " ;// 2 spacje
      wyswietl_kolory_graczy2(tab[2]);
      cout << "\033[0m" ;
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';
      std::cout << "" << '\n';




        }


  void dodajk(karta card, gracz tab[], int i) {
    if (card.kolor =="♣") {
      std::cout << " rozmiar przed dodaniem karty spowrotem: " << tab[i].trefl.size()<< '\n';
          tab[i].trefl.push_back(card);
          std::cout << "rozmiar po dodaniu karty: " << tab[i].trefl.size()<< '\n';
    }
    if (card.kolor =="♦") {
      std::cout << " rozmiar przed dodaniem karty spowrotem: " << tab[i].caro.size()<< '\n';
      tab[i].caro.push_back(card);
      std::cout << "rozmiar po dodaniu karty: " << tab[i].caro.size()<< '\n';

    }
    if (card.kolor =="♥") {
      std::cout << " rozmiar przed dodaniem karty spowrotem: " << tab[i].kier.size()<< '\n';
      tab[i].kier.push_back(card);
      std::cout << "rozmiar po dodaniu karty: " << tab[i].kier.size()<< '\n';

    }
    if (card.kolor =="♠") {
      std::cout << " rozmiar przed dodaniem karty spowrotem: " << tab[i].pik.size()<< '\n';
        tab[i].pik.push_back(card);
        std::cout << "rozmiar po dodaniu karty: " << tab[i].pik.size()<< '\n';

    }
  }

  bool jaki_kolor(gracz tab[], karta card,int i){
     bool p = 0;
     if (tab[i].trefl.empty()&&card.kolor== "♣") {
       p = 1;
     }
     if (tab[i].caro.empty()&&card.kolor== "♦") {
       p = 1;
     }
     if (tab[i].kier.empty()&&card.kolor== "♥") {
       p = 1;
     }
     if (tab[i].pik.empty()&&card.kolor== "♠") {
       p = 1;
     }

     return p;

  }


void ruch(licytacja &lic, gracz tab[], int &nr_ruchu, int &j, karta kar[]) {
  for (int i = 0; i < 4; i++) {
    zly_kolor:
    bool ki=0, tr=0,ca=0,pi=0;
    wyswietl_kolory_graczy(tab,i);
    std::cout << "teraz jest ruch gracza :::   " << tab[i].pozycja << '\n';
    string r;
    cin >> r;
    int n;
    string k;
    n = war(r);
    k = kol(r);
    std::cout << " n i k to  :::::  " << n << k << '\n';
    karta card;


    card = znajdz(tab[i],n,k,tr,ca,ki,pi);
    while (card.kolor == "nic" && card.f == "nic"){
      std::cout << "wykonaj ruch ponownie" << '\n';
      std::cout << "teraz jest ruch gracza :::   " << tab[i].pozycja << '\n';
      string r;
      cin >> r;
      int n;
      string k;
      n = war(r);
      k = kol(r);
      std::cout << " n i k to  :::::  " << n << k << '\n';
      card = znajdz(tab[i],n,k,tr,ca,ki,pi);
    }

    kar[i]=card;

    if ((kar[i].kolor!=kar[0].kolor)&&(jaki_kolor(tab,kar[0],i)==false)) {
      if (kar[i].kolor =="♣") {
        if (!tab[i].trefl.empty()||tr==1) {

          dodajk(kar[i],tab,i);
          std::cout << " zły kolor taka akcja jest nie dozwolona wykonaj ruch ponownie" << '\n';

          goto zly_kolor;
        }

      }

        if (kar[i].kolor =="♦") {
          if (!tab[i].caro.empty()||ca==1) {
                dodajk(kar[i],tab,i);
            std::cout << " zły kolor taka akcja jest nie dozwolona wykonaj ruch ponownie" << '\n';

            goto zly_kolor;
          }

  }

          if (kar[i].kolor =="♥") {
            if (!tab[i].kier.empty()||ki==1) {
                dodajk(kar[i],tab,i);
              std::cout << " zły kolor taka akcja jest nie dozwolona wykonaj ruch ponownie" << '\n';

              goto zly_kolor;
            }

        }

            if (kar[i].kolor =="♠") {
              if (!tab[i].pik.empty()||pi==1) {
                  dodajk(kar[i],tab,i);
                std::cout << " zły kolor taka akcja jest nie dozwolona wykonaj ruch ponownie" << '\n';

                goto zly_kolor;
              }

            }



      }


      }
    }



void gra(licytacja &lic, gracz tab[]) {
  //kolejnośc w pierwszym ruchu
  if (lic.rozgrywajacy_gracz.pozycja=="N") {
    tab[0]=lic.E;
    tab[1]=lic.S;
    tab[2]=lic.W;
    tab[3]=lic.N;
  }

  if (lic.rozgrywajacy_gracz.pozycja=="S") {
    tab[0]=lic.W;
    tab[1]=lic.N;
    tab[2]=lic.E;
    tab[3]=lic.S;
  }

  if (lic.rozgrywajacy_gracz.pozycja=="W") {
    tab[0]=lic.N;
    tab[1]=lic.E;
    tab[2]=lic.S;
    tab[3]=lic.W;
  }

  if (lic.rozgrywajacy_gracz.pozycja=="E") {
    tab[0]=lic.S;
    tab[1]=lic.W;
    tab[2]=lic.N;
    tab[3]=lic.E;
  }


  for (int i = 1; i < 14; i++) {
    int j = -5;
    karta kar[4];

    ruch(lic,tab,i,j,kar);
  }


}

void oliczanie_wyniku(/* arguments */) {
  /* code */
}

void bot(/* arguments */) {
  /* code */
}



int main()
{
  std::vector<karta> talia(52);

  std::vector<karta> reka1;
  std::vector<karta> reka2;
  std::vector<karta> reka3;
  std::vector<karta> reka4;

  std::srand ( unsigned ( std::time(0) ) );

  tworztalie(talia);
  wyswietl(talia);
  tasuj(talia);
  wyswietl(talia);

  rozdaj(reka1,reka2,reka3,reka4,talia);
 wyswietl_reke(reka1);
  wyswietl_reke(reka2);
  wyswietl_reke(reka3);
  wyswietl_reke(reka4);

  gracz N,S,W,E;
  para NS,WE;

  tworz_graczy(reka1,reka2,reka3,reka4,N,S,W,E);
/*
  N = gracz(reka1,"N");
  S = gracz(reka2,"S");
  W = gracz(reka3,"W");
  E = gracz(reka4,"E");*/



  sortuj(N);
  sortuj(S);
  sortuj(W);
  sortuj(E);

std::cout << "N:" << '\n';

std::cout << "" << '\n';
  wyswietl_kolor(N.trefl);
  std::cout << "" << '\n';
  std::cout << N.trefl.size() << '\n';
  std::cout << "" << '\n';
  wyswietl_kolor(N.caro);
    std::cout << "" << '\n';
  std::cout << N.caro.size() << '\n';
  std::cout << "" << '\n';
  wyswietl_kolor(N.kier);
    std::cout << "" << '\n';
  std::cout << N.kier.size() << '\n';
  std::cout << "" << '\n';
  wyswietl_kolor(N.pik);
    std::cout << "" << '\n';
  std::cout << N.pik.size() << '\n';
  //std::cout << S.pik.size() << '\n';


std::cout << "S:" << '\n';



  std::cout << "" << '\n';
    wyswietl_kolor(S.trefl);
    std::cout << "" << '\n';
    std::cout << S.trefl.size() << '\n';
    std::cout << "" << '\n';
    wyswietl_kolor(S.caro);
      std::cout << "" << '\n';
    std::cout << S.caro.size() << '\n';
    std::cout << "" << '\n';
    wyswietl_kolor(S.kier);
      std::cout << "" << '\n';
    std::cout << S.kier.size() << '\n';
    std::cout << "" << '\n';
    wyswietl_kolor(S.pik);
      std::cout << "" << '\n';
    std::cout << S.pik.size() << '\n';

    std::cout << "W:" << '\n';






    std::cout << "" << '\n';
      wyswietl_kolor(W.trefl);
      std::cout << "" << '\n';
      std::cout << W.trefl.size() << '\n';
      std::cout << "" << '\n';
      wyswietl_kolor(W.caro);
        std::cout << "" << '\n';
      std::cout << W.caro.size() << '\n';
      std::cout << "" << '\n';
      wyswietl_kolor(W.kier);
        std::cout << "" << '\n';
      std::cout << W.kier.size() << '\n';
      std::cout << "" << '\n';
      wyswietl_kolor(W.pik);
        std::cout << "" << '\n';
      std::cout << W.pik.size() << '\n';

      std::cout << "E:" << '\n';



      std::cout << "" << '\n';
        wyswietl_kolor(E.trefl);
        std::cout << "" << '\n';
        std::cout << E.trefl.size() << '\n';
        std::cout << "" << '\n';
        wyswietl_kolor(E.caro);
          std::cout << "" << '\n';
        std::cout << E.caro.size() << '\n';
        std::cout << "" << '\n';
        wyswietl_kolor(E.kier);
          std::cout << "" << '\n';
        std::cout << E.kier.size() << '\n';
        std::cout << "" << '\n';
        wyswietl_kolor(E.pik);
          std::cout << "" << '\n';
        std::cout << E.pik.size() << '\n';
        std::cout << "" << '\n';
        std::cout << "" << '\n';

        std::cout << N.punkty << '\n';
        std::cout << S.punkty << '\n';
        std::cout << W.punkty << '\n';
        std::cout << E.punkty << '\n';





  NS = para(N,S,"NS");
  WE = para(W,E,"WE");

std::cout << "" << '\n';

  std::cout << "NS punkty:" << NS.punkty<< '\n';

  std::cout << "WE punkty:" << WE.punkty<< '\n';
  std::cout << "" << '\n';

  std::cout << "NS długości kolorów:" << '\n';

  std::cout << "trefl "<< NS.dtrefl << '\n';
  std::cout << "caro "<< NS.dcaro << '\n';
  std::cout << "kier "<< NS.dkier << '\n';
  std::cout << "pik "<< NS.dpik << '\n';

  std::cout << "" << '\n';


  std::cout << "WE długości kolorów:" << '\n';

  std::cout << "trefl "<< WE.dtrefl << '\n';
  std::cout << "caro "<<WE.dcaro << '\n';
  std::cout << "kier "<< WE.dkier << '\n';
  std::cout << "pik "<< WE.dpik << '\n';
  przygotowanie(NS,WE);

  //std::cout << "jaką licytację chcesz wykonać ? : wpisz auto lub reczna :" << '\n';




 /*
rzecz do wyboru licytacji automatycznej lub ręcznej
 string jaka_licytacja;

 cin >> jaka_licytacja;

  if (jaka_licytacja=="auto") {

  }

  if (jaka_licytacja=="reczna") {
      licytacja lic=licytacja(NS,WE,N,S,W,E,2,N);
  }*/
  licytacja lic=licytacja(NS,WE,N,S,W,E,1);
  gracz tab[4];

  gra(lic,tab);










    return 0;
}
