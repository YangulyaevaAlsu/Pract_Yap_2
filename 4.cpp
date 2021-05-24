#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

bool TrialDivision(uint32_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint32_t i = 3; i <= (uint32_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int n=1000;
    uint32_t min=1ULL<<(n-3);
    uint32_t max = (min << 2) + 2;
    uint32_t g;
    vector <int> s;
    s.resize(1000,0);
    bool flag;
    mt19937 gen(clock());
    uniform_int_distribution<uint32_t> rnd(min,max);
    for (int i = 0; i < 1000; i++) {
        flag = true;
        while(flag) {
            g = rnd(gen);
            if (TrialDivision(g)) {
                flag = false;
            }
        }
        s.at(i) = g;
        cout<<s.at(i)<<endl;
    }
    int alt;
    for (int i = 0; i < 998; i++) {
        for (int j = i + 1; j < 1000; j++)
            if(s.at(i) > s.at(j)) {
                alt = s.at(i);
                s.at(i)= s.at(j);
                s.at(j) = alt;
            }
    }
    cout << "Минимальное число = " << s.front() << endl;
    cout << "Максимальное число = " << s.back() << endl;
    return 0;
}
