#include <iostream>
#include "tim.h"
#include "privilegovani.h"
#include "mec.h"
using namespace std;
int main() {
    Igrac i("aleksa",1200);
    Igrac i2("petar",800);
    Igrac i3("slavoljub",1400);
    Igrac i4("nikola",600);
    Igrac i5("nemanja");
    Igrac i6("milos");

    Tim t("Partizan",11);
    Tim t2("Crvena Zvezda",11);
    Tim t3("Rad",11);

    t.prikljuci(i,2);
    t.prikljuci(i2,1);
    t2.prikljuci(i3,3);
    t2.prikljuci(i4,0);
    t3.prikljuci(i5,1);
    t3.prikljuci(i6,2);
    /*
    Tim t3=t;
    Tim t4(t);
    cout <<t4 <<"\n";
    cout <<i.dohvVrednost() <<"\n";
    t.povecajSvima(10);
    cout <<t <<"\n";
    if(t==t2) cout << "isti su";
    else cout <<"nisu isti";
    */
    Par par1(t,t2);
    Par par2(t2,t);
    Par par3(t3,t);
    Mec mec1(par1);
    Mec mec2(par2);
    Mec mec3(par3);
    //ISHODI: 0-NERESENO, 1-POBEDA DOMACIN, 2-POBEDA GOST
    mec1.odigraj(2);
    cout << mec1 << "\n";
    mec2.odigraj(0);
    cout << mec2 <<"\n";
    mec3.odigraj(1);
    cout << mec3 <<"\n";
    //cout <<t.srVrednost();
    return 0;
}
