#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N;
    ll ans1 = 0,sum = 0,ans2 = 0;
    cin >> N;
    vector<ll> a(N);

    rep(i, N)
        cin >> a[i];

    //偶数番目が生の時
    rep(i,N){
        sum += a[i];

        if(i%2 == 0 && sum <= 0){
            ans1 += abs(sum)+1;
            sum = 1;
        }

        else if(i%2 == 1 && sum >= 0){
            ans1 += abs(sum)+1;
            sum = -1;
        }
    }

    sum = 0;

    rep(i,N){
        sum += a[i];

        if(i%2 == 0 && sum >= 0){
            ans2 += abs(sum)+1;
            sum = -1;
        }

        else if(i%2 == 1 && sum <= 0){
            ans2 += abs(sum)+1;
            sum = 1;
        }
    }

    cout << min(ans1,ans2) << endl;

    
    return 0;
}