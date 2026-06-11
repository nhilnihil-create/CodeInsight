#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int cnt=0;
    rep(i,n){
        int q,w;
        q = a[i];
        if(a[q-1]-1 == i) cnt++;
    }
    cout << cnt/2 << endl;
}