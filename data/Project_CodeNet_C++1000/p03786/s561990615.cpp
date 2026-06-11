#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);

    rep(i, N) cin >> a[i];

    //昇順にソート
    sort(a.begin(), a.end());

    vector<ll> sum(N+1, 0);
    for(int i = 1; i < N+1; i++){
        sum[i] = sum[i-1] + a[i-1];
    }

    int val = N-1;
    for(int i = N-1; i >= 1; i--){
        if(sum[i]*2 >= a[i]) val = i;
        else break;
    }

    int ans = N-val+1;
    cout << ans << endl;
    return 0;
}