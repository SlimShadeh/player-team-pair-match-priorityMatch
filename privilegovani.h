#ifndef ZAD4_PRIVILEGOVANI_H
#define ZAD4_PRIVILEGOVANI_H
#include "tim.h"

class GVrednostPremala{
    friend ostream& operator<<(ostream& os,const GVrednostPremala &t){
        return os << "***Nema tekuceg!***\n";
    }
};

class Privilegovani :public Tim {
public:
    Privilegovani(const string &naz,int maks,int min) : Tim(naz,maks) {
        minVrednost=min;
    }
    Privilegovani(const Privilegovani& p);
    Privilegovani(Privilegovani &&p);

    Privilegovani &operator=(const Privilegovani &p);
    Privilegovani &operator=(Privilegovani &&p);

    ~Privilegovani() override {}

    void prikljuci(Igrac &ig, int poz) override{
        if(ig.dohvVrednost()<minVrednost) throw GVrednostPremala();
        Tim::prikljuci(ig,poz);
    }

    friend ostream &operator<<(ostream &os,const Privilegovani &t);

private:
    int minVrednost;

    void pisi(ostream &os) const override;
};


#endif //ZAD4_PRIVILEGOVANI_H
