#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
    
int main(){
    int ai, ao, bi, bo;
    cin >> ai >> ao >> bi >> bo;
    int a = 0;
    int b = 0;
    int ans = 0;
    rep(i, 101){
        if(ai == i) a = 1;
        if(bi == i) b = 1;
        if(ao == i) a = 0;
        if(bo == i) b = 0;
        if(a == 1 && b == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}