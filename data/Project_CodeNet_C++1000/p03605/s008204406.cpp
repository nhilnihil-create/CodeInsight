#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    string n;
    cin >> n;
    repi(i,2,0){
        if(n[i]-'0' == 9){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}