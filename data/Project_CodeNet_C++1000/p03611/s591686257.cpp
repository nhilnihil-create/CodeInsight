#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    int max_a = 0;
    vector<int> cnt(1000000);
    rep(i, N){
        int a;
        cin >> a;
        cnt[a]++;
        cnt[a+1]++;
        cnt[a+2]++;
    }
    for(auto aaa: cnt){
        max_a = max(max_a, aaa);
    }
    cout << max_a << endl;
    return 0;
}
