#include <iostream>
#include <cmath>
#include <vector>
#include<string>
#include<random>
#include<cstdlib>
#include<ctime>
#include<algorithm>
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


gracz :: gracz(){}
para :: para(){}
karta :: karta(){}




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















karta :: karta(int starszenstwo,int w){
if(starszenstwo==0)
    kolor="♣";
if(starszenstwo==1)
    kolor = "♦";
if(starszenstwo==2)
    kolor="♥";
if(starszenstwo==3)
    kolor = "♠";

pun=0;

if (w==0) {
  f="2";
  /* code */
}
if (w==1) {
  f="3";
  /* code */
}

if (w==2) {
  f="4";
  /* code */
}

if (w==3) {
  f="5";
  /* code */
}

if (w==4) {
  f="6";
  /* code */
}

if (w==5) {
  f="7";
  /* code */
}
if (w==6) {
  f="8";
  /* code */
}

if (w==7) {
  f="9";
  /* code */
}
if (w==8) {
  f="10";
  /* code */
}
if (w==9) {
  f="J";
  pun=1;
  /* code */
}
if (w==10) {
  f="Q";
  pun=2;
  /* code */
}
if (w==11) {
  f="K";
  pun=3;
  /* code */
}
if (w==12) {
  f="A";
  pun=4;
  /* code */
}







zagrana=0;
atu=0;



}

 void tworztalie(vector < karta >& talia){
  for (int i=0;i < 4; i++) {


    for (int j = 0; j < 13; j++) {


      talia[j+13*i]=karta(i,j);


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
    std::cout << kolor[i].f <<kolor[i].kolor << " " << '\n';
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

void ruch(/* arguments */) {
  /* code */
}

void gra(/* arguments */) {
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




    return 0;
}
