/**
*    created: 12.05.2020 09:07:32
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    //aの中に奇数の要素が奇数個あるとダメ
    //偶数個あればよい
    int k = 0;
    rep(i,n){
        if(a[i]%2)
            k++;
    }
    if(k%2) cout << "NO" << endl;
    else cout << "YES" << endl;
}