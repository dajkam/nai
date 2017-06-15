#include <iostream>
#include <cmath>
#include <vector>
#include<string>

//2♠, 2♣, 2♥, 2♦

using namespace std;


class karta {
public :
string kolor;
string f;
int starszenstwo;
bool atu;
bool zagrana;
int w;



karta();
karta(int starszenstwo, int w);

};
karta :: karta(){}
karta :: karta(int starszenstwo,int w){
if(starszenstwo==1)
    kolor="♣";
if(starszenstwo==2)
    kolor = "♦";
if(starszenstwo==3)
    kolor="♥";
if(starszenstwo==4)
    kolor = "♠";

if (w==2) {
  f="2";
  /* code */
}
if (w==3) {
  f="3";
  /* code */
}

if (w==4) {
  f="4";
  /* code */
}

if (w==5) {
  f="5";
  /* code */
}

if (w==6) {
  f="6";
  /* code */
}

if (w==7) {
  f="7";
  /* code */
}
if (w==8) {
  f="8";
  /* code */
}

if (w==9) {
  f="9";
  /* code */
}
if (w==10) {
  f="10";
  /* code */
}
if (w==11) {
  f="J";
  /* code */
}
if (w==12) {
  f="Q";
  /* code */
}
if (w==13) {
  f="K";
  /* code */
}
if (w==14) {
  f="A";
  /* code */
}











}

 void tworztalie(vector < karta >& talia){
  for (int i=1;i <= 4; i++) {


    for (int j = 2; j <= 14; j++) {
      int n=i-1;

      talia[j+n*13]=karta(i,j);


    }

  }







}







void wyswietl(vector < karta >& talia){
 for (int i=1;i <= 4; i++) {


   for (int j = 2; j <= 14; j++) {
       int n=i-1;


     std::cout << " " << talia[j+n*13].f << talia[j+n*13].kolor ;





   }


   std::cout  << '\n';
   std::cout << '\n';
   std::cout  << '\n';
 }







}




int main()
{
  std::vector<karta> talia(57);
  std::vector<karta> reka(14);
  tworztalie(talia);
  wyswietl(talia);
    return 0;
}
