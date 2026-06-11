#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    rep(i,n) {
        int A;
        cin >> A, --A;
        a[i] = A;
    }
    for(int i = 0; i < n; ++i){
        if(a[a[i]]==i) ans++;
        
    }
    cout << (ans+1)/2 << endl;
    return 0;
}