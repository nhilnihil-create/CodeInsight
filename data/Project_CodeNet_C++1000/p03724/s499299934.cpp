#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;



int main() {
    int n, m; cin >> n >> m;
    int cnt[n+1];
    rep(i, n) cnt[i+1] = 0;
    int a, b;
    rep(i, m){
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    int count = 0;
    rep(p, n){
       count += cnt[p+1] % 2;
    }
    if (count > 1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }

}

