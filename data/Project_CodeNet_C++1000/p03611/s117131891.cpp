#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N), cnt(100010, 0);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N){
        if(a[i] - 1 >= 0) cnt[a[i]-1]++;
        cnt[a[i]]++;
        cnt[a[i]+1]++;
    }
    cerr << max_element(cnt.begin(), cnt.end()) - cnt.begin() << endl;
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
    return 0;
}