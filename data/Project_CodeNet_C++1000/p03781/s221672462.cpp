//070 ARC C - GO HOME
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int64 x; cin >> x;
    int64 ans;
    for(int i=1;i<=1000000000;++i){
        if (( i * ( i + 1 ) / 2 ) >= x ) { ans = i; break;}
    }
    cout << ans << endl;
}