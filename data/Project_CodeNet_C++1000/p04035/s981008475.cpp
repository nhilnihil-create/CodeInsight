#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int n;
    ll l;
    cin >> n >> l;

    vector<ll> a(n);

    rep(i, n){
        cin >> a[i];
    }

    bool able = false;
    int last;

    rep(i, n - 1){

        if(a[i] + a[i + 1] >= l){
            able = true;
            last = i + 1;
            break;
        }
    }

    if(able){
        cout << "Possible" << endl;

        for(int i = 1; i < last; i++){
            cout << i << endl;
        }

        for(int i = n - 1; i >= last; i--){
            cout << i << endl;
        }

        
    }else{
        cout << "Impossible" << endl;
    }



    return 0;
}
