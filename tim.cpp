#include "tim.h"

Igrac &Tim::operator[](int i) {
    int br=0;
    for(Elem *pok=prvi;pok;pok=pok->sled){
        if(i==br) return pok->igrac;
        br++;
    }
}

ostream &operator<<(ostream &os, const Tim &t) {
    t.pisi(os);
    return os;
}

void Tim::pisi(ostream &os) const{
    os << naziv <<'[';
    for(Elem *pok=prvi;pok;pok=pok->sled){
        if(pok!=prvi) os << ',' <<pok->igrac;
        else os <<pok->igrac;
    }
    os <<']';
}

Tim::Tim(const Tim &t) {
    naziv=t.naziv;
    maksIgraca=t.maksIgraca;
    prvi=t.prvi;
    posl=t.posl;
}

Tim::Tim(Tim &&t) {
    naziv=t.naziv;
    maksIgraca=t.maksIgraca;
    for(Elem *pok=t.prvi;pok;){
        Elem *posl=(!prvi ? prvi : posl->sled)=new Elem(pok->igrac,pok->pozicija);
        Elem *stari=pok;
        pok=pok->sled;
        delete stari;
    }
}

Tim &Tim::operator=(const Tim &t) {
    if(this!=&t){
        naziv=t.naziv;
        maksIgraca=t.maksIgraca;
        prvi=t.prvi;
        posl=t.posl;
    }
    return *this;
}

Tim &Tim::operator=(Tim &&t) {
    if(this !=&t){
        naziv=t.naziv;
        maksIgraca=t.maksIgraca;
        for(Elem *pok=t.prvi;pok;){
            Elem *posl=(!prvi ? prvi : posl->sled)=new Elem(pok->igrac,pok->pozicija);
            Elem *stari=pok;
            pok=pok->sled;
            delete stari;
        }
    }
    return *this;
}

Tim::~Tim() {
    prvi=posl=nullptr;
}

bool operator==(Tim &t1,Tim &t2) {
    int nije=0;
    if(t1.naziv==t2.naziv && t1.maksIgraca==t2.maksIgraca){
        return t1.jednaki(t2);
    }
    return false;
}


double Tim::srVrednost() {
        double sr=0;
        for(Elem *pok=prvi;pok;pok=pok->sled){
            sr+=pok->igrac.dohvVrednost();
        }
        return sr/this->dohvBrojIgraca();
}

void Tim::smanjiSvima(int s) {
    for(Elem *pok=prvi;pok;pok=pok->sled){
        pok->igrac.smanji(s);
    }
}

void Tim::povecajSvima(int s) {
    for(Elem *pok=prvi;pok;pok=pok->sled){
        pok->igrac.povecaj(s);
    }
}

bool Tim::jednaki(const Tim &t) {
    Elem *pok1=prvi;
    Elem *pok2=t.prvi;
    while(pok1 && pok2){
        if(pok1->igrac!= pok2->igrac || pok1->pozicija != pok2->pozicija){
            return false;
        }
        pok1=pok1->sled;
        pok2=pok2->sled;
    }
    if(!pok1 && !pok2) return true;
    return false;
}

void Tim::prikljuci(Igrac &ig, int poz) {
    if(!prvi){
        prvi=posl=new Elem(ig,poz);
        return;
    }
    else if(prvi->pozicija>poz){
        Elem *privremeni = new Elem(ig,poz);
        privremeni->sled=prvi;
        prvi=privremeni;
    }
    else{
        for(Elem *pok=prvi;pok->sled;pok=pok->sled){

            if(pok->sled->pozicija>poz){
                Elem *privremeni = new Elem(ig,poz);
                privremeni->sled=pok->sled;
                pok->sled=privremeni;
                return;
            }
        }
        posl->sled= new Elem(ig,poz);
        posl=posl->sled;
    }
}

int Tim::dohvBrojIgraca() {
    int br=0;
    for(Elem *pok=prvi;pok;pok=pok->sled){
        br++;
    }
    return br;
}

