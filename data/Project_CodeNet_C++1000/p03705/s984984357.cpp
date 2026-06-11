#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)


int main(){
    ll N,A,B,rs=0,Nans,min,max;
    cin >> N >> A >> B;

    if(N == 1){
        if(A == B)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }else if(A > B){
        cout << 0 << endl;
    }else{
        Nans = N - 2;
        max = B * (Nans+1) + A;
        min = A * (Nans+1) + B;
        rs = max - min + 1;
        cout << rs << endl;
    }

    return 0;

}