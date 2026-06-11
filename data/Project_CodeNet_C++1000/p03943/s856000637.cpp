#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(ALL(a));
    if(a[0] + a[1] == a[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}