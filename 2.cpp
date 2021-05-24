#include <iostream>
#include <random>
#include <cmath>
using namespace std;

bool TrialDivision(uint64_t n)

{

    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint64_t i = 3; i <= (uint64_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    uint64_t num;
    bool flag;
    uint64_t a[3];
    mt19937_64 gen(clock());
    for (int i = 0; i < 3; i++) {
        flag = true;
        while(flag) {
            num = gen();
            if (TrialDivision(num)) {
                flag = false;
            }
            a[i] = num;
        }
        cout<<i+1<<" число:"<<a[i]<<endl;
    }
    return 0;
}
