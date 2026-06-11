#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k; cin >> n >> k;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(RALL(l));
    int sum = 0;
    rep(i,k) sum += l[i];
    cout << sum << endl;
}