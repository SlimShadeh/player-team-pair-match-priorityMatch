#include "privilegovani.h"

ostream &operator<<(ostream &os, const Privilegovani &t) {
    t.pisi(os);
    return os;
}

void Privilegovani::pisi(ostream &os) const {
    os << naziv << '-' << minVrednost <<'[';
    for(Elem *pok=prvi;pok;pok=pok->sled){
        if(pok!=prvi) os << ',' <<pok->igrac;
        else os <<pok->igrac;
    }
}

Privilegovani::Privilegovani(const Privilegovani &p) : Tim(p) {
    minVrednost=p.minVrednost;
}

Privilegovani::Privilegovani(Privilegovani &&p) : Tim(p) {
    minVrednost=p.minVrednost;
}

Privilegovani &Privilegovani::operator=(const Privilegovani &p) {
    if(this!=&p){
        naziv=p.naziv;
        maksIgraca=p.maksIgraca;
        prvi=p.prvi;
        posl=p.posl;
        minVrednost=p.minVrednost;
    }
    return *this;
}

Privilegovani &Privilegovani::operator=(Privilegovani &&p) {
    if(this !=&p){
        naziv=p.naziv;
        maksIgraca=p.maksIgraca;
        minVrednost=p.minVrednost;
        for(Elem *pok=p.prvi;pok;){
            Elem *posl=(!prvi ? prvi : posl->sled)=new Elem(pok->igrac,pok->pozicija);
            Elem *stari=pok;
            pok=pok->sled;
            delete stari;
        }
    }
    return *this;
}

