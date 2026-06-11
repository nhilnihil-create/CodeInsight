#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    string S;
    cin >> S;
    int ans = INF;
    rep(i,26) {
        char x = 'a' + i;
        string T = S;
        bool c = true;
        rep(j,T.size()) {
            if (T[j]!=x){
                c = false;
            }
        }
        if (c){
            ans = 0;
            break;
        }
        else {
            int tmp = 0;
            while(1) {
                bool b = true;
                tmp++;
                rep(j,T.size()-1) {
                    if (T[j+1]==x) {
                        T[j] = x;
                    }
                    else if (T[j]==x) {
                        continue;
                    }
                    else {
                        b = false;
                    }
                }
                if (b) {
                    ans = min(ans,tmp);
                    break;
                }
                T.pop_back();

            }
        }

    }
    cout << ans << endl;
}
