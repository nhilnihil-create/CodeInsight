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
    vector<ll> a(n);
    int m1 = 0;
    int m2 = 0;
    int m4 = 0;
    int cnt = 0;

    rep(i,n){
        cnt = 0;
        cin >> a[i];

        rep(j,2){
            if(a[i] %2 == 0 && a[i] != 0){
                cnt++;
                a[i] /= 2;
            }
        }

        if(cnt == 2) m4++;
        if(cnt == 1) m2++;
        if(cnt == 0) m1++;
    }

    if(m2 == 0){
        if(m4 >= m1 - 1){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }

    if(m1 <= m4) cout << "Yes" << endl;
    else cout << "No" << endl;
}

