#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

bool TrialDivision(uint64_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint64_t i = 3;
         i <= (uint64_t) sqrt(n); i+=2)
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
        system_clock::time_point begin = system_clock::now();
        while(flag) {
            num = gen();
            if (TrialDivision(num)) {
                flag = false;
            }
            a[i] = num;
        }
        system_clock::time_point end = system_clock::now();
        duration <double> delta = end-begin;
       cout<<i+1<<" число:"<<a[i]<<"\t";
        cout << delta.count() << " секунд" << endl;
    }
    return 0;
}
