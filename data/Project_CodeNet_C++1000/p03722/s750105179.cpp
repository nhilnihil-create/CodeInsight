#include <bits/stdc++.h>
 
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MAX_E=2000;

const int MAX_V=1000;

struct edge {int from, to; ll cost;};
edge es[MAX_E];
ll d[MAX_V];
int V, E;
const ll INF =1LL << 50;

bool bellmanford(int s)
{
    rep(i, V)
        d[i]=INF;
    
    d[s]=0;
    
    for(int j=0; j<2*V; j++)
    {
        for(int i=0; i<E; i++)
        {
            edge e = es[i];
            if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                if(j>=V-1 && e.to==V-1) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool findNegativeLoop()
{
    FILL0(d);
    for(int i=0; i<V; i++)//あくまで回数
    {
        for(int j=0; j<E; j++)
        {
            edge e = es[j];
            if(d[e.to] > d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                if(i==V-1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    cin >> V >> E;

    rep(i, E)
    {
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--;
        es[i].to--;
        es[i].cost = -1*es[i].cost;
    }

    if(bellmanford(0))
    {
        cout << "inf" << endl;
        return 0;
    }
  

    cout << -1*d[V-1] << endl;

 
    return 0;
}
 