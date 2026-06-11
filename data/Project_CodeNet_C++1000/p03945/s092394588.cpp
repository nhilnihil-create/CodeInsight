#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    cin >> S;
    char before = S[0];
    int cnt = 0;
    for(int i=0;i<S.size();i++){
        if(before != S[i]){
            cnt++;
        }
        before = S[i];
    }
    cout << cnt << endl;
    return 0;
}