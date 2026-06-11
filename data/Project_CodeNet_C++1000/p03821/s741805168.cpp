#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())

#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9+7:合同式の法
 
int main(){
    ll n;
    cin >> n;

    vector<int> a,b;
    REP(i,n){
        ll tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        a.push_back(tmp1);
        b.push_back(tmp2);
    }

    ll total = 0;
    REPD(i,n){
        ll tmp = (b[i] - (a[i]+total)%b[i]);
        if(tmp != b[i]){
            total += tmp;
        }
        /*
        if(b[i] == 1){
            total--;
        }
        */
    }
    cout << total << endl;
    return 0;
}