#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    string s,t;
    cin >> N >> s >> t;
    int ans;
    rep(i,N+1) {
        string tmp = s.substr(0,i);
        tmp += t;
        if (tmp.substr(0,N)==s) {
            ans = i+N;
            break;
        }
    }
    cout << ans << endl;
}
