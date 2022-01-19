#ifndef ZAD4_TIM_H
#define ZAD4_TIM_H
#include "igrac.h"

class Tim {
public:
    Tim(const string &naz,int maks){
        naziv=naz;
        maksIgraca=maks;
        prvi=posl= nullptr;
    }
    Tim(const Tim& t);
    Tim(Tim &&t);

    Tim &operator=(const Tim &t);
    Tim &operator=(Tim &&t);

    virtual ~Tim();

    virtual void prikljuci(Igrac &ig,int poz);

    int dohvBrojIgraca();

    Igrac &operator[](int i);

    double srVrednost();

    void smanjiSvima(int s);

    void povecajSvima(int s);

    friend bool operator==(Tim &t1,Tim &t2);

    bool jednaki(const Tim& t);

    friend ostream &operator<<(ostream &os,const Tim &t);
protected:
    string naziv;
    int maksIgraca;

    struct Elem{
        Igrac &igrac;
        int pozicija;
        Elem *sled;
        Elem(Igrac &igrac1,int poz):igrac(igrac1){
            pozicija=poz;
            sled=nullptr;
        }
    };
    Elem *prvi,*posl;
    virtual void pisi(ostream &os) const;
};


#endif //ZAD4_TIM_H
