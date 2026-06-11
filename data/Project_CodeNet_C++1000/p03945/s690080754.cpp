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
    char now = s[0];
    int ans = 0;
    repi(i,n,1){
        if(now != s[i]){
            ans++;
            now = s[i];
        }
    }
    cout << ans << endl;
    return 0;
}