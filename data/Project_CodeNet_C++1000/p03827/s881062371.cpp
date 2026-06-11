#define _GLIBCXX_DEBUG

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

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

    string s;
    cin >> s;

    ll count = 0;
    //ll before_count;
    ll max_x = 0;
    REP(i,n){
        //before_count = count;
        if(s[i] == 'I'){
            count++;
        }
        else{
            count--;
        }
        max_x = max(max_x,count);
    }
    if(max_x < 0){
        max_x = 0;
    }
    cout << max_x << endl;
    return 0;
}