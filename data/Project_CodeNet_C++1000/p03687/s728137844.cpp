#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
  
/*------------------------------------------------------------------*/

int main(){
    string s; cin >> s;
    int n = s.size(); 
    set<char> se;
    rep(i, n) se.insert(s[i]);
    if(se.size() == n){
        cout << n / 2 << endl;
        return 0;
    }
    int ans = 100;
    for(auto it : se){
        int max_len = 0;
        int pos = -1;
        rep(i, n){
            if(s[i] == it){
                max_len = max(max_len, int(i) - pos - 1);
                pos = i;
            }
        }
        max_len = max(max_len, n - pos - 1);
        ans = min(ans, max_len);
        //cout << ans << " " << max_len << endl;
    }
    cout << ans << endl;
}
