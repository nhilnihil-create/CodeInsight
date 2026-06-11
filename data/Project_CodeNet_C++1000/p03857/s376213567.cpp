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
class UnionFind{
private:
    vector<int> vec;
public:
    void init(int N){
        vec.resize(N);
        for(int a = 0;a < N;a++)
        {
            vec[a]=-1;
        }
    }
    int root(int a)
    {
        if(vec[a] < 0)return a;
        else return vec[a] = root(vec[a]);
    }
    bool connect(int a,int b)
    {
        a = root(a);
        b = root(b);
        if(a==b)return false;
        if(vec[a] > vec[b])swap(a,b);
        vec[a] += vec[b];
        vec[b] = a;
        return true;
    }
    bool check(int a,int b){
        a = root(a);
        b = root(b);
        if(a==b)return true;
        else return false;
    }
};
int main(){
    CIN(N);CIN(K);CIN(L);
    UnionFind Uni1,Uni2;
    Uni1.init(N+1);
    Uni2.init(N+1);
    REP(a,K){
        CIN(b);CIN(c);
        Uni1.connect(b,c);
    }
    REP(a,L){
        CIN(b);CIN(c);
        Uni2.connect(b,c);
    }
    map<pair<int,int>,int> mp;
    REP(a,N){
        Uni1.root(a+1);
        Uni2.root(a+1);
    }
    REP(a,N){
        mp[make_pair(Uni1.root(a+1),Uni2.root(a+1))]++;
    }
    REP(a,N){
        cout<<mp[make_pair(Uni1.root(a+1),Uni2.root(a+1))]<<" ";
    }
    return 0;
}
