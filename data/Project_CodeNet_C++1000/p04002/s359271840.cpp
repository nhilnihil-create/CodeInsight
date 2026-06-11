#include<bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define LCIN(n) LL(n);cin >> (n)
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
LL w[10];
int main(){
    LCIN(H);LCIN(W);LCIN(N);
    V<pair<LL,LL>> vec;
    REP(a,N){
        LCIN(b);LCIN(c);
        vec.pb(make_pair(b-1,c-1));
    }
    map<pair<int,int>,int> mp;
    int dx[]={1,1,1,0,-1,-1,-1,0,0};
    int dy[]={1,0,-1,-1,-1,0,1,1,0};
    REP(a,N){
        for(int b = 0;b < 9;b++){
            if(vec.at(a).second+dx[b] >=1&&vec.at(a).second+dx[b] < W-1&&vec.at(a).first + dy[b] >= 1&&dy[b]+vec.at(a).first < H-1){
                if(mp.find(make_pair(vec.at(a).first + dy[b],vec.at(a).second+dx[b])) == mp.end()){
                    mp[make_pair(vec.at(a).first + dy[b],vec.at(a).second+dx[b])]=1;
                }else{
                    mp[make_pair(vec.at(a).first + dy[b],vec.at(a).second+dx[b])]++;
                }
            }
        }
    }
    LL sum = 0;
    FOREACH(a,mp){
       // cout<<a.second <<" "<<a.first.first<<" "<<a.first.second<<endl;
       w[a.second]++;
    }
    for(int a = 0;a < 10;a++){
        sum += w[a];
    }
    w[0]=(H-2)*(W-2)-sum;
    for(int a = 0;a < 10;a++){
        COUT(w[a]);
    }
    return 0;
}
