#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF = 2e9
#define LINF = 1e18
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << "=" << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO")
#define Yes(n) cout << ((n) ? "Yes" : "No")
#define PI 3.141592653589793

int main(){
        
    vector<string> s(3);

    rep(i,3)cin >> s[i];

    rep(i,3){
        cout << (char)(s[i][0]-('a'-'A'));
    }
    cout << endl;

}