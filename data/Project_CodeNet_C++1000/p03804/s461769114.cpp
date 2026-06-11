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

    int n,m;
    cin >> n >> m;

    vector<string> a(n);
    vector<string> b(m);

    rep(i, n){
        cin >> a[i];
    }

    rep(i, m){
        cin >> b[i];
    }

    bool ans = false;

    [&](){
        for(int i = 0; i + m - 1 < n; i++){
            for(int j = 0; j + m - 1 < n; j++){
                bool tmp = true;

                [&](){
                    rep(k, m){
                        rep(l, m){
                            if(b[k][l] != a[i + k][j + l]){
                                tmp = false;
                                return;
                            }
                        }
                    }
                }();

                if(tmp){
                    ans = true;
                    return;
                }
            }
        }
    }();

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
