#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    vector<int> a(3);
    rep(i,3)cin >> a.at(i);
    sort(a.begin(),a.end());
    int ans=3;
    rep(i,2){
        if(a.at(i)==a.at(i+1))ans--;
    }
    cout << ans << endl;
}