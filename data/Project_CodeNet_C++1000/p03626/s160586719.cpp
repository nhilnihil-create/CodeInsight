#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second

typedef pair<lint, lint> P;
const lint MOD = 1e9+7;
const lint INF = MOD * MOD;
const int MAX = 100005;

int main(){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    vector<int> pattern; pattern.push_back(-1);
    rep(i, n){
        if(s1[i] == s2[i]) pattern.push_back(1);
        else{
            pattern.push_back(0);
            i++;
        }
    }
    lint ans = 1;
    rep(i, pattern.size() - 1){
        int x = pattern[i], y = pattern[i + 1];
        if(x == -1){
            if(y == 0) ans *= 6;
            else ans *= 3;
        }
        if(x == 0){
            if(y == 0) ans *= 3;
            else ans *= 1;
        }
        if(x == 1){
            if(y == 0) ans *= 2;
            else ans *= 2;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}