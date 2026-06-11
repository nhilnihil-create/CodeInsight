#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n,m;
    cin >> n>> m;
    ll nn,mm;
    nn = n;
    mm = m;
    if(llabs(n-m) > 1){
        cout << 0 << endl;
        return 0;
    }
    ll answer = 1;
    if(n==m)answer*=2;
    REP(i,nn){
        //cout << n << endl;
        answer = answer*n%MOD;
        n--;
    }
    REP(i,mm){
        //cout << m << endl;
        answer = answer*m%MOD;
        m--;
    }

    cout << answer << endl;

    
    return 0;
}