#include <iostream>
#include <cmath>
#include <vector>
#include<string>

//2♠, 2♣, 2♥, 2♦

using namespace std;


class karta {
public :
string kolor;
int starszenstwo;
bool atu;
bool zagrana;
string figura;
int wartosc;

karta();
karta(int starszenstwo, int wartosc);

};
karta :: karta(){}
karta :: karta(int starszenstwo,int watosc){
if(starszenstwo==1)
    kolor="♣";
if(starszenstwo==2)
    kolor = "♦";
if(starszenstwo==3)
    kolor="♥";
if(starszenstwo==4)
    kolor = "♠";

if(wartosc==2)
    figura="2";
if(wartosc==3)
    figura="3";
if(wartosc==4)
    figura="4";
if(wartosc==5)
    figura="5";
if(wartosc==6)
    figura="6";
if(wartosc==7)
    figura="7";
if(wartosc==8)
    figura="8";
if(wartosc==9)
    figura="9";
if(wartosc==10)
    figura="10";
if(wartosc==11)
    figura ="J";
if(wartosc==12)
    figura ="Q";
if(wartosc==13)
    figura ="K";
if(wartosc==14)
    figura= "A";



}



int main()
{
    cout << "Hello world!" << endl;

      cout << "Hello world!" << endl;
      if(0==0)
      //3333
      //45567
    return 0;
} 
