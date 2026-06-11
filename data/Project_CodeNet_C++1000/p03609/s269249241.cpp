#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int x,t;
    cin >> x >> t;
    cout << max(x-t,0) << endl;
    return 0;
}