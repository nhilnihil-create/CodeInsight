#include <bits/stdc++.h>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()

typedef long long ll;

using namespace std;

/*
各個数とったときの平均値を総当たりし、
最も高い平均値になる個数を求める
その後その個数のうちに最も値が小さいものの数を
取った個数のなかと、残った個数の中から調べて組み合わせを求める
*/

int main(){
    
    int n,a,b;
    cin >> n >> a >> b;

    vector<ll> v;

    rep(i,n){
        ll tmp;
        cin >> tmp;
        v.pback(tmp);
    }

    sort(ALL(v));
    reverse(ALL(v));

    ll sum = 0;

    rep(i, a - 1){
        sum += v[i];
    }

    long double bestavg = 0.0;
    long double d = 0.0000001;
    vector<int> bestcount;

    for(int i = a - 1; i < b; i++){

        sum += v[i];

        if(bestavg < (long double)sum / (i + 1)){
            bestavg = (long double)sum / (i + 1);
            bestcount.clear();
            bestcount.pback(i + 1);
        }else if(bestavg  == (long double)sum / (i + 1)){
            bestcount.pback(i + 1);
        }

    }

    cout << setprecision(24) << bestavg << endl;

    ll ans = 0;

    rep(i, bestcount.size()){

        int num = bestcount[i];

        ll lowest = v[num - 1];

        int innercount = 0;
        int outercount = 0;

        for(int i = 0; i < num; i++){
            if(v[i] == lowest) innercount++;
        }

        for(int i = num; i < n; i++){
            if(v[i] == lowest) outercount++;
        }

        ll tmp = 1;

        //cerr << innercount << endl;
        //cerr << outercount << endl;

        for(int i = 1; i <= innercount; i++){
            tmp = tmp * (innercount + outercount + 1 - i);
            tmp = tmp / i;
        }

        ans += tmp;

    }

    cout << ans << endl;
    return 0;
}