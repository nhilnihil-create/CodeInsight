//001 AGC A - BBQ Easy 2016/07/16
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int n; cin >> n;
    vector<int> l(n + n);
    rep(i ,n*2) cin >> l[i];
    int64 sum=0;
    sort(l.begin(),l.end());
    for(int i=0;i<n*2;i+=2){
        sum+=l[i];
    }
    cout << sum << endl;
}