#ifndef ZAD4_IGRAC_H
#define ZAD4_IGRAC_H
#include <string>
#include <iostream>
using namespace std;

class Igrac {
public:
    Igrac(string i,int vr=1000) {
        ime=i;
        vrednost=vr;
    }

    void povecaj(double pr);
    void smanji(double pr);

    int dohvVrednost() const {
        return vrednost;
    }
    friend bool operator==(const Igrac &i1,const Igrac &i2);

    friend ostream &operator<<(ostream &os,const Igrac &i);
private:
    string ime;
    int vrednost;
};


#endif //ZAD4_IGRAC_H
