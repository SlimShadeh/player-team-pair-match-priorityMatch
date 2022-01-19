#ifndef ZAD4_MEC_H
#define ZAD4_MEC_H
#include "tim.h"
#include "par.h"
#include <iostream>
using namespace std;

class GNeodigrano{
    friend ostream& operator<<(ostream& os,const GNeodigrano &t){
        return os << "***Mec nije odigran!***\n";
    }
};

enum vrsta {NERESENO,POBEDA_DOMACIN,POBEDA_GOST,NEODIGRANO};
class Mec {
public:

    Mec(Par<Tim> &t) :  timovi(t){
        ishod=NEODIGRANO;
    }

    void odigraj(int i);

    bool odigran() const{
        if(ishod!=NEODIGRANO) return true;
        return false;
    }
    Par<int> poeni() const;

    friend ostream& operator<<(ostream &os, const Mec &m);

private:
    Par<Tim> timovi;
    vrsta ishod;
};


#endif //ZAD4_MEC_H
