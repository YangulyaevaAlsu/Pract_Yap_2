#include <iostream>
#include <ctime>
#include <locale>
using namespace std;

int main ()

{

    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    time_t t = time(NULL);
    tm * ptm;
    char buff [100];
    ptm = localtime(&t);
    strftime(buff, 100, "%c", ptm);
    cout << buff<< endl;

    return 0;

}
