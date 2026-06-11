#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll mod = 1000000007;
 
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    int p=0;
    rep(i, 0, n){
        if(s[i] == '(')p++;
        else p--;
        if(p < 0){
            ans = '(' +ans;
            p++; 
        }
        if(i == n-1 && p > 0){
            int j = p;
            while(p > 0){
                ans += ')';
                p--;
            }
        }
    }
    cout << ans << endl;
}