#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    cin >> S;
    int cnt = 0;
    char pre = S[0];
    rep(i,S.size()){
        if(S[i]!=pre){
            cnt++;
            pre = S[i];
        }
    }
    cout << cnt << endl;
    return 0;
}