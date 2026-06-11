#include"bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<< #str << " " str<<endl

constexpr int INF = (1 << 30);
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7



int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int>> edges(N);
    REP(i,M)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> route;
    set<int> use;
    int now = 0;
    route.push_back(now);
    use.insert(now);

    start:;
    for(auto next:edges[now])
    {
        if(use.find(next)==use.end())
        {
            now=next;
            route.push_back(now);
            use.insert(now);
            goto start;
        }
    }

    reverse(route.begin(),route.end());
    now=0;
    start2:;
    for(auto next:edges[now])
    {
        if(use.find(next)==use.end())
        {
            now=next;
            route.push_back(now);
            use.insert(now);
            goto start2;
        }
    }

    cout << route.size()<<endl;
    for(auto pos:route)
    {
        cout << pos + 1 << " ";
    }
    cout << endl;
   
    return 0;
}
