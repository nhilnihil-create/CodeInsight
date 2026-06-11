#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;

typedef long long ll;

int main(){

    int n,k;
    cin >> n >> k;

    vector<int> h(n);

    rep(i, n){
        cin >> h[i];
    }

    ll ans = LLONG_MAX;

    for(int bit = 0; bit < (1<<n); bit++){

        vector<int> tmph = vector<int>(h);

        int preh = 0;
        ll tmpans = 0;

        for(int i = 0; i < n; i++){
            if(bit & (1<<i)){
                if(tmph[i] <= preh){
                    tmpans = tmpans + ((preh + 1) - tmph[i]);
                    tmph[i] = preh + 1;
                    preh = preh + 1;
                }else{
                    preh = tmph[i];
                }
            }else{
                preh = max(preh, tmph[i]);
            }

        }

        int count = 1;
        int tmp = tmph[0];

        rep(i, n - 1){
            if(tmp < tmph[i + 1]){
                count++;
                tmp = tmph[i + 1];
            }
        }

        if(count >= k){
            ans = min(ans, tmpans);
        }
    }

    cout << ans << endl;

    return 0;
}
