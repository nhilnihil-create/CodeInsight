#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long x;
    cin >> x;
    long long i = 1;
    long long d = 1;
    while (d < x) {
        i++;
        d = i * (i + 1) / 2;
    }
    cout << i;
    return 0;
}
