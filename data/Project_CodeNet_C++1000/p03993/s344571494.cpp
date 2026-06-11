#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    int ans = 0;
    rep(i, n){
        if(i == a[a[i]-1]-1){
            ans++;
        }
    }

    cout << ans / 2 << endl;

    return 0;
}