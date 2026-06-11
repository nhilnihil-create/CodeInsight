#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a.at(i);
    rep(i,0,n){
        a.at(i)--;
    }
    int now = 0;
    int cnt = 0;
    while(now!=1&&cnt<=n){
        now = a.at(now);
        cnt++;
    }
    cout << ((now==1) ? cnt : -1) << endl;
}