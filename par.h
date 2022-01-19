#ifndef ZAD4_PAR_H
#define ZAD4_PAR_H
#include <iostream>
using namespace std;


template <typename T>
class Par {
public:
    Par(const T &pr,const T &dr) : prvi(pr) ,drugi(dr){

    }

    T *getPrvi()  {
        return &prvi;
    }

    void setPrvi(T *pr) {
        prvi = pr;
    }

    T *getDrugi()  {
        return &drugi;
    }

    void setDrugi(T *dr) {
        drugi = dr;
    }
    friend bool operator==(const Par &p1,const Par &p2){
        if(p1.prvi==p2.prvi && p2.drugi==p1.drugi) return true;
        return false;
    }

    friend ostream &operator<<(ostream &os,const Par &p){
        return os << '[' <<p.prvi << '-' << p.drugi <<']';
    }

private:
    T prvi,drugi;
};



#endif //ZAD4_PAR_H
