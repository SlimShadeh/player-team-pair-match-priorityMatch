#include "mec.h"

void Mec::odigraj(int i) {
    switch(i){
        case 0:
            ishod=NERESENO;
            break;
        case 1:
            ishod=POBEDA_DOMACIN;
            timovi.getPrvi()->povecajSvima(10);
            timovi.getDrugi()->smanjiSvima(10);
            break;
        case 2:
            ishod=POBEDA_GOST;
            timovi.getPrvi()->smanjiSvima(10);
            timovi.getDrugi()->povecajSvima(10);
            break;
    }
}

Par<int> Mec::poeni() const {
    switch(ishod){
        case 0:
            return Par(1,1);
        case 1:
            return Par(3,0);
        case 2:
            return Par(0,3);
        default:
            throw GNeodigrano();
    }
}

ostream &operator<<(ostream &os, const Mec &m) {
     os << m.timovi ;
    if(m.odigran()) os << "\n" << m.poeni();
    return os;
}
