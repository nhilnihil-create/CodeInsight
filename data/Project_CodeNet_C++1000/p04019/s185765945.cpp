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

    string st;
    cin >> st;

    int n = 0;
    int w = 0;
    int s = 0;
    int e = 0;

    int size = st.size();

    rep(i, size){
        if(st[i] == 'N'){
            n++;
        }else if(st[i] == 'W'){
            w++;
        }else if(st[i] == 'S'){
            s++;
        }else{
            e++;
        }
    }

    bool ans = true;

    if((n == 0 && s > 0) || (s == 0 && n > 0)) ans = false;

    if((e == 0 && w > 0) || (w == 0 && e > 0)) ans = ans && false;

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
