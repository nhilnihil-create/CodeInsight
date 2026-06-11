#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll>t(n);
    REP(i,n)cin >> t[i];
    SORT(t);
    ll answer = 0;
    ll i=0;
    while(i < n){
        ll j=i+1;
        
        while(t[j]-t[i] <= k && (j-i+1)<=c){
            j++;
        }
        i = j;
        answer++;
        cerr<<i << " " << answer << endl;
    }
    
    cout << answer << endl;
    return 0;
}