#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>

int main(){
    ll N, M;
    cin >> N >> M;
    VS s(N);
    rep(i, 0, N){
        cin >> s[i];
    }
    rep(j, 0, N){
        cout << s[j] << endl;
        cout << s[j] << endl;
    }
    return 0;
}
