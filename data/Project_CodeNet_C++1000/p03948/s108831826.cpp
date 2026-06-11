#include<bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define SCIN(n) string(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<int,int>
#define I vector<int>
#define S set<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
#define rmsame(a) sort(ALL(a)),a.erase(unique(ALL(a)), a.end())

typedef string::const_iterator State;
class PalseError {};
class Edge{
public:
    int from,to,value;
    Edge(int a,int b,int c){
        from = a;
        to = b;
        value = c;
    }
    Edge(int a,int b){
        from = a;
        to = b;
    }
};
int calc(int n,I vec){
    int ins = 0;
    REP(a,vec.size()){
        ins += abs(vec.at(a)-n);
    }
    return ins;
}
int main(){
    CIN(N);CIN(T);
    I vec;
    pair<I,I> pa;
    int ins = 0;
    REP(a,N){
        CIN(b);
        vec.pb(b);
    }
    int mi = INF;
    int count1 = 0;
    int count2 = 0;
    REP(a,N){
        mi = min(mi,vec.at(a));
        if(vec.at(a) - mi > ins){
            ins =vec.at(a) - mi;
            count1 = 1;
            count2 = 1;
        }else if(vec.at(a) - mi == ins){
            count1++;
            count2++;
        }
    }
    COUT(min(count1,count2));
    return 0;
}
