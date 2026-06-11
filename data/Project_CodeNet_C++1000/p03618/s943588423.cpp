#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    string s; cin >> s;
    int sl=s.length();
    ll ans=((ll)sl*(ll)(sl-1))/2;
    map<char,int> m;
    rep(i,sl) m[s[i]]++;
    for(auto x : m) ans-=((ll)(x.second)*(ll)(x.second-1))/2;
    cout << ans+1 << endl;
return 0;
}