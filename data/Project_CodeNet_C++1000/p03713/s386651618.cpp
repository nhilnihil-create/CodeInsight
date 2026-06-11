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
#define ALL(obj) (obj).begin,(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll h,w;
    cin >> h >> w;
    ll a = min(w,h);
    ll b = max(w,h);
    ll sa,sb,sc;
    ll answer = 10000000000;
    FOR(i,1,b){
        sa = a*i;
        sb = (b-i)*(a/2);
        sc = (b-i)*(a-(a/2));
        ll smax = max({sa,sb,sc});
        ll smin = min({sa,sb,sc});
        if(smax-smin < answer){
            answer = smax-smin;
        }
        if(answer == 0)
            break;
    }
    FOR(i,1,b){
        sa = a*i;
        sb = a*((b-i)/2);
        sc = a*((b-i)-((b-i)/2));
        ll smax = max({sa,sb,sc});
        ll smin = min({sa,sb,sc});
        if(smax-smin < answer){
            answer = smax-smin;
        }
        if(answer == 0)
            break;
    }
    
    swap(a,b);

    FOR(i,1,b){
        sa = a*i;
        sb = (b-i)*(a/2);
        sc = (b-i)*(a-(a/2));
        ll smax = max({sa,sb,sc});
        ll smin = min({sa,sb,sc});
        if(smax-smin < answer){
            answer = smax-smin;
        }
        if(answer == 0)
            break;
    }
    FOR(i,1,b){
        sa = a*i;
        sb = a*((b-i)/2);
        sc = a*((b-i)-((b-i)/2));
        ll smax = max({sa,sb,sc});
        ll smin = min({sa,sb,sc});
        if(smax-smin < answer){
            answer = smax-smin;
        }
        if(answer == 0)
            break;
    }
    cout << answer << endl;
    return 0;
}