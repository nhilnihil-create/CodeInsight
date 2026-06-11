#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

//後ろから考える Mulitaple Arrays

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    
    for(ll i = 0;i < N;i++){
        cin >> A.at(i) >> B.at(i);
    }

    ll rs = 0,amari=0;

    for(ll i = N -1;i >= 0;i--){
            A.at(i) += rs;
        if(A.at(i) % B.at(i) != 0){
            amari = A.at(i) % B.at(i);
            rs += B.at(i) - amari;
        }
    }

    cout << rs << endl;
    

}