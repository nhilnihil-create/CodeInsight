#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();

    string ans = "";

    rep(i,N) {
        if (i==N-1) {
            int idx = S[i] - 'a';
            idx += K;
            idx %= 26;
            ans += idx + 'a';
        }
        else if (S[i]=='a') {
            ans += 'a';
        }
        else {
            int idx = S[i] - 'a' + 1;
            if (K>=27-idx) {
                ans += 'a';
                K -= 27-idx;
            }
            else {
                ans += S[i];
            }
        }
    }
    cout << ans << endl;
}
