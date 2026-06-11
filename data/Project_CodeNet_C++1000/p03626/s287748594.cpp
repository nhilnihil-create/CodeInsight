#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
static const int mod = 1e9+7;
int main(){
    int n, now; sc(n)
    string s1, s2;
    cin >> s1 >> s2;
    bool check;
    ll ans;
    if (s1[0] == s2[0]){
        check = true;
        ans = 3;
        now = 1;
    }else {
        check = false;
        ans = 6;
        now = 2;
    }
    while (now < n){
        if (s1[now] == s2[now]){
            if (check) ans = ans * 2 % mod;
            check = true;
            now += 1;
        }else {
            if (check) ans = ans * 2 % mod;
            else ans = ans * 3 % mod;
            check = false;
            now += 2;
        }
    }
    cout << ans << endl;
    return 0;
}