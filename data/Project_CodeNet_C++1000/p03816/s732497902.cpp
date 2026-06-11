#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    //偶奇、どの場合が最適がに注目
    int n; cin >> n;
    map<int, int> ma;
    rep(i,n) {
        int a; cin >> a;
        ma[a]++;
    }
    int res = ma.size();
    if((n-res)%2!=0) res--;
    cout << res << endl;
}