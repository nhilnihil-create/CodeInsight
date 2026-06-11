#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define SORT(s) sort((s).begin(),(s).end())

ll f(ll n,ll x) {
    return n/x;
}

int main(){
    ll a,b,x; cin >> a  >> b >> x;
    if(a==0){
        cout << f(b,x) + 1 << endl;
    }else{
       cout << f(b,x) - f(a-1,x) << endl;
    }
}


