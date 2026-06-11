#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, a;
    cin >> n;
    map<int, int> cnt;
    rep(i, n){
        cin >> a;
        cnt[a]++;
    }
    if(cnt.size() % 2) cout << cnt.size() << endl;
    else cout << cnt.size() - 1 << endl;
    return 0;
}