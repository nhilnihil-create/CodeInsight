#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007

int main(void){
    ll n;
    cin >> n;

    string s1, s2;
    cin >> s1;
    cin >> s2;

    ll curr = 0;
    ll prev = 0;
    ll ans = 0;
    rep(i, 0, n){
        if(s1[i] == s2[i]) curr = 0;
        else curr = 1;


        if(i == 0){
            if(curr == 0){
                ans = 3;
            }else{
                ans = 3 * 2;
                i++;
            }
        }else{
            if(curr == 1){
                if(prev == 0){
                    ans *= 2;
                    ans %= MOD;
                }else{
                    ans *= 3;
                    ans %= MOD;
                }
                i++;
            }
            else if(prev == 0){
                ans *= 2;
                ans %= MOD;
            }
        }
        prev = curr;
    }

    cout << ans << endl;
    return 0;
}
