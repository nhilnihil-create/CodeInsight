#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<char> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    int n;
    cin >> n;
    vector<int> a(3*n);
    rep(i,3*n) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    ll ans = 0;
    rep(i,2*n){
        if (i%2 != 0){ans += a[i];}
    }
    cout << ans;
}