#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // 4通り考える
    for(int bit=0;bit<4;bit++){
        vector<int> ans(n,0);
        for(int i=0;i<2;i++){
            if((bit>>i)&1){
                ans[i] = 1;
            }else ans[i] = 0;
        }
        for(int i=1;i<n-1;i++){
            if(s[i]=='o'){
                if(ans[i]==0){
                    ans[(i+1)%n] = ans[(i-1+n)%n];
                }else{
                    ans[(i+1)%n] = (ans[(i-1+n)%n]+1)%2;
                }
            }else{
                if(ans[i]==0){
                    ans[(i+1)%n] = (ans[(i-1+n)%n]+1)%2;
                }else ans[(i+1)%n] = ans[(i-1+n)%n];
            }
        }
        bool ok = 0;
        if(s[n-1]=='o'){
            if(ans[n-1]==0 && ans[0] == ans[n-2]){
                ok = 1;
            }else if(ans[n-1]==1 && ans[0]!= ans[n-2]){
                ok = 1;
            }
        }else{
            if(ans[n-1]==0 && ans[0] != ans[n-2]){
                ok = 1;
            }else if(ans[n-1] == 1 && ans[0]== ans[n-2]){
                ok = 1;
            }
        }
        bool ok2 = 0;
        if(ok){
            if(s[0]=='o'){
                if(ans[0]==0 && ans[1] == ans[n-1]){
                    ok2 = 1;
                }else if(ans[0] == 1 && ans[1] != ans[n-1]){
                    ok2 = 1;
                }
            }else {
                if(ans[0]==0 && ans[1] != ans[n-1]){
                    ok2 = 1;
                }else if(ans[0] == 1 && ans[1] == ans[n-1]){
                    ok2 = 1;
                }
            }
        }
        if(ok2){
            rep(i,n)cout << (ans[i]==0?"S":"W");
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
