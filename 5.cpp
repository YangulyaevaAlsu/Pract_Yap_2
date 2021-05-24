#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
using namespace std;

bool TrialDivision (uint64_t n)
{
    if (n  == 0)
        return false;
    for ( uint64_t i = 2; i <= (uint64_t) sqrt(n); i ++) {
        if (n % i == 0) {
            return false;
        }

    }
    return true;
}
int BitCount (uint64_t n)
{
    int i;
    int res = 0;
for (i=0 ;i<64 ;i++)
    {
        if((n>>i)%2==1) res++;
    }
    return res;
}
int main ()
{
    uint64_t L;
    uint64_t maxNum= 0xFFFFFFFFFFFFFFFF;
    for (L = 2; L < maxNum ; L++) {
        if  (TrialDivision(L) && (BitCount(L)) == 2)   {
            cout << "Десятичное число: " << L << "\t" << "Шестнадцатеричное число: " << maxNum<<L << endl;

        };
        
    }
    return 0;
}
