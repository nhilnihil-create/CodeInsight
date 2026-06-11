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

    string s;
    cin >> s;

    int ai, zi;

    rep(i, s.size()){
        if(s[i] == 'A'){
            ai = i;
            break;
        }
    }

    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'Z'){
            zi = i;
            break;
        }
    }

    cout << zi - ai + 1 << endl;
    return 0;
}
