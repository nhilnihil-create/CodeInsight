#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> a(n); rep(i,n) cin >> a[i];
    sort(all(a));

    int kind = 1;

    rep(i,n-1){
        if(a[i] != a[i+1]) kind++;
    }

    if(kind %2 == 0){
        cout << kind -1 << endl;
    }
    else cout << kind << endl;
}
