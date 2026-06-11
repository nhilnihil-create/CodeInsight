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

    int k, t;
    cin >> k >> t;

    vector<pair<int,int>> a(t);

    rep(i, t){
        int tmp;
        cin >> tmp;

        a[i] = make_pair(tmp, i + 1);
    }

    sort(ALL(a));

    vector<int> eat(k);

    eat[0] = a[t - 1].second;
    a[t - 1].first = a[t - 1].first - 1;
    sort(ALL(a));

    for(int i = 1; i < k; i++){

        if(eat[i - 1] == a[t - 1].second){

            if(t >= 2 && a[t - 2].first > 0){
                eat[i] = a[t - 2].second;
                a[t - 2].first = a[t - 2].first - 1;
            }else{
                eat[i] = a[t - 1].second;
                a[t - 1].first = a[t - 1].first - 1;
            }
        }else{
            eat[i] = a[t - 1].second;
            a[t - 1].first = a[t - 1].first - 1;
        }
        sort(ALL(a));
    }

    /*
    rep(i, k){
        cerr << eat[i] << " ";
    }
    cerr << endl;
    */

    int ans = 0;

    rep(i, k - 1){
        if(eat[i] == eat[i + 1]) ans++;
    }

    cout << ans << endl;

    return 0;
}
