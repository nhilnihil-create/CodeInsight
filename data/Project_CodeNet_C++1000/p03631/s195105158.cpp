#include <iostream>
#include <cstring>
#define Yes cout << "Yes"
#define No cout << "No"
using namespace std;
string a;
int main()
{
    cin >> a;
    if (a[0] == a[2])
        Yes;
    else
        No;
    return 0;
}
