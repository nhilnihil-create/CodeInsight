#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    int n,m; cin >> n >> m;
    int student[n][2];
    int points[m][2];
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 2;j++){
            cin >> student[i][j];
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < 2;j++){
            cin >> points[i][j];
        }
    }
    
    for(int i = 0;i < n;i++){
        ll ans = LLONG_MAX;
        int point = 0;
        for(int j = 0;j < m;j++){
            ll c = (ll)abs(student[i][0]-points[j][0])+(ll)abs(student[i][1]-points[j][1]);
            if(c < ans){
              ans = c;
              point = j+1;
            }
        }
        cout << point << endl;
    }
    
}

