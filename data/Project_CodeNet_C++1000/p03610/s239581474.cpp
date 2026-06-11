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
    string s;
    cin >> s;
    int n = s.size();
    repi(i,n,0){
        if(!(i&1))cout << s[i];
    }
    cout << endl;
    return 0;
}