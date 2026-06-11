#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ull N;
    cin >> N;
    ull power = 1;
    ull m = 1000000007;
    for (ull i = 1; i <= N; ++i)
    {
        power = (power * i) % m;
    }
    cout << power << endl;
}