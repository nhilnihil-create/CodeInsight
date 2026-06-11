#include <bits/stdc++.h>
using namespace std;

#define cc(x) cout << (x) << endl
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define repi(i,a,b) for(int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<long long> vll;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const ll inf = 1LL<<58;
const int iinf = 1<<30;
ll mod = 1e9+7;
int main(){
    ll n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    ll ans=0;
    ll i=0;
    bool now=0;
    if(s1[0]==s2[0]){
        ans=3;
        i++;
        now=0;
    }else{
        ans=6;
        i+=2;
        now=1;
    }
    while(i<n){
        // cc(i);
        // cc(ans);
        if(s1[i]==s2[i]){
            i++;
            if(now){
                ans*=1;
            }else{
                ans*=2;
            }
            now=0;
        }else{
            i+=2;
            if(now){
                ans*=3;
            }else{
                ans*=2;
            }
            now=1;
        }
        ans=ans%mod;
    }
    cc(ans);
}