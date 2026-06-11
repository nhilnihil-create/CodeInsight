#include <bits/stdc++.h>

using ll = long long;

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);
 

void solve() {
    int N;
    cin >> N;
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0;
    ll ans = 1;
    bool prev;
    if(s1[i] == s2[i]){
        ans *= 3ll;
        prev = true;
        i++;
    }
    else{
        ans *= 6ll;
        prev = false;
        i += 2;
    }

    for(i;i < N; i++){
        if(s1[i] == s2[i]){
            if(prev) {
                ans = (ans * 2ll) % mod;
            }
            else{
                ans = (ans * 1ll) % mod;
            }
            prev = true;
        }
        else{
            if(prev) {
                ans = (ans * 2ll) % mod;
            }
            else{
                ans = (ans * 3ll) % mod;
            }
            prev = false;
            i++;
        }
    }
    cout << ans << endl;
}
 
int main() {
    solve();
    return 0;
}
