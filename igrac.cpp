#include "igrac.h"

bool operator==(const Igrac &i1, const Igrac &i2) {
    if(i1.vrednost==i2.vrednost && i1.ime==i2.ime) return true;
    return false;
}

ostream &operator<<(ostream &os, const Igrac &i) {
    return os << i.ime << '#' << i.vrednost;
}

void Igrac::povecaj(double pr) {
    vrednost=vrednost+ vrednost*pr/100;
}

void Igrac::smanji(double pr) {
    vrednost=vrednost - vrednost*pr/100;
    if(vrednost <0) vrednost=0;
}
