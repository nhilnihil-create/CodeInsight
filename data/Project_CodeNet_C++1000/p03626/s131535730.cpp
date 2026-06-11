#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int N;
    string S,T;
    cin >> N >> S >> T;
    // N == 1　と, N == 2　の組み合わせ
    // Z          aa                 Zの後、Zは、*2で、　Zの後 aa は、2*1で、aa　の後、Zは、*1、   aaの後、aaは、左下と右上が同じことがあるので、
    // Z          bb                 Z　　　Z　　　　　  Z    bb           bb      Z          bb     bb   3通り
    int ans = 3;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            if(S[i] != T[i]){
                i++;
                ans = 6;
            }
            continue;
        }
        if(S[i] != T[i] && S[i-1] != T[i-1]) {
            ans*=3;
        }
        else if(S[i] == T[i] && S[i-1] != T[i-1]) {
            continue;
        }
        else {
            ans*=2;
        }
        if(S[i] != T[i]) {
            i++;
        }
        ans%=INF;
    }
    cout << ans << endl;
}
