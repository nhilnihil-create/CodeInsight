#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int h,w;
    cin >> h >> w;

    vector<string> s(h);

    rep(i, h){
        cin >> s[i];
    }

    rep(i, h + h){
        rep(j, w){
            cout << s[i / 2][j];
        }
        cout << endl;
    }
    return 0;
}
