#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int sum = 0;
    repi(i,10000,1){
        if(a * i % b == 0)continue;
        if(c % (a * i % b) == 0){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}