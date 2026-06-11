#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n,m;
    cin >> n >> m;
    vector<LL> x(n);
    vector<LL> y(m);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
    }

    LL ysum = 0;

    for(int i = m-1; i >= 0; i--){
        ysum += y[i]*(m-1-i) - y[i]*i;
        ysum %= MOD;
    }

    LL sum = 0;

    for(int i = n-1; i >= 0;i--){
        //sum += ((((((x[i]*(n-1-i))%MOD)*m)%MOD)*(m-1))%MOD)*ysum;
        sum += ((x[i]*(n-1-i))%MOD)*ysum;
        sum %= MOD;
        //sum -= ((((((x[i]*i)%MOD)*m)%MOD)*(m-1))%MOD)*ysum;
        sum -= ((x[i]*i)%MOD)*ysum;
        sum %= MOD;
    }

    cout << sum << endl;
    
    return 0;
}