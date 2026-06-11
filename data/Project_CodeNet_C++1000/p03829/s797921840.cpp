#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin >> n >> a >> b;
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> d(n-1);
    for(int i = 1; i < n; i++) {
        d[i-1]=x[i]-x[i-1];
    }
//    for(int i = 0; i < n-1; i++) {
//        cout << d[i] << " ";
//    }
//    cout << "\n";
    sort(d.begin(),d.end());

    int cnt=0;
    int idx=0;
    while(a*d[idx]<b) {
        cnt+=a*d[idx];
        idx++;
        if(idx==n-1) break;
    }
    cnt+=b*(n-1-idx);
    cout << cnt << "\n";
    return 0;
}