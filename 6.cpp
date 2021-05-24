#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
bool TrialDivision(uint32_t n)
{
    if (n== 0)
        return false;
    for (uint32_t i=2; i<=(uint32_t)sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int BitCount(uint32_t n)
{
    int i;
    int res = 0;
    for (i=0; i<32; i++) {
        if((n>>i)%2==1) res++;
    }
    return res;
}
int main()
{
    uint32_t L;
    uint32_t minNum = 0x80000001;
    uint32_t maxNum = 0xFFFFFFFF;
    for(L=minNum; L<maxNum; L++) {
        if ((BitCount(L) == 3) && (TrialDivision(L))) {
            cout<<"Десятичные число: "<<L<<"\t"<<"Шестнадцатеричное число :"<<maxNum<<L<<endl;
        }
    }
    return 0;
}
