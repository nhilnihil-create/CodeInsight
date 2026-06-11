//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define ALL(v) (v).begin(), (v).end()

int main(){
    ll N, L;
    cin >> N >> L;
    VS s(N);
    rep(i,0,N) cin >> s[i];
    sort(ALL(s));
    rep(i,0,N){
        cout << s[i];
    }
    cout << endl;
    return 0;
}