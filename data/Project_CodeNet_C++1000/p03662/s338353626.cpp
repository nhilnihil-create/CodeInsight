#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<limits>
#include<sstream>      

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const int inf = numeric_limits<int>::max() /4;
const ll linf = numeric_limits<ll>::max() /4;
const ull ulinf = numeric_limits<ull>::max()/4;
const double pi = acos(-1);
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int dx8[8]={-1,0,1,-1,1,-1,0,1};
const int dy8[8]={-1,-1,-1,0,0,1,1,1};

#define p_queue(i) priority_queue<i> 
#define rp_queue(i) priority_queue<i, vector<i>, greater<i>> 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define mod(i) ((i)%(ll)(1e9 + 7))
#define divm(a,b) (mod(a * modpow((ll)b,(ll)(1e9+5))))
#define rsort(a,b,c) sort(a, b, greater<c>())
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.end(), v.begin());
#define ft first
#define sd second
#define pb push_back
#define it insert
#define sz(x) ((int)(x).size())
#define lb(a,n,k) (lower_bound(a,a+n,k) - a) 
#define vlb(a,k)  (lower_bound(a.begin(),a.end(),k) - a.begin())
#define ub(a,n,k) (upper_bound(a,a+n,k) - a) 
#define vub(a,k)  (upper_bound(a.begin(),a.end(),k) - a.begin())
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return

ll modpow(ll i,ll j){ ll tmp=1; while(j){ if(j%2)tmp=mod(tmp*i);i=mod(i*i);j/=2;}return tmp;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}

//ll ncr[100][100];
//ll nCr(int n, int r){if(n==r) ret ncr[n][r] = 1; if(r==0) ret ncr[n][r] = 1; if(r==1) ret ncr[n][r] = n;if(ncr[n][r]) ret ncr[n][r]; ret ncr[n][r] = nCr(n-1,r) + nCr(n-1,r-1);}

//ll npr[100][100]={};
//ll nPr(int n,int r){if(npr[n][r])ret npr[n][r];if(r==0)ret npr[n][r] = 1;if(r==1)ret npr[n][r] = n;ret npr[n][r] = n * nPr(n-1,r-1);}

//ll nHr(int n,int r){ret nCr(n+r-1,r);}

///////////////////////////////////////////////////////////////////////////


struct edge{int to ,cost;};

class dijkstra{
private:
	typedef pair<ll,int> pa; //first:最短距離 second:頂点番号
	int V,E;//頂点数,辺数
public:
	vector<vector<edge>> G;
	vector<ll> d;

	dijkstra(int v, int e){
		V = v;
		E = e;
		G.resize(V+5);
		d.resize(V+5);
	}
	void run(int s){//O(|E|log|V|)
    	rp_queue(pa) que;
    	fill(d.begin(),d.end(),linf);
    	d[s] = 0;
    	que.push(pa(0,s));
    	while(!que.empty()){
        	pa p = que.top();que.pop();
        	int v = p.sd;
        	if(d[v] < p.ft)continue;
        	rep(i,0,sz(G[v])){
            	edge e = G[v][i];
            	if(d[e.to] > d[v] + e.cost){
                	 d[e.to]=d[v] + e.cost;
                 	que.push(pa(d[e.to],e.to));
            	}
        	}
    	}
	}

	void addpath(int a,int b,int c){
		edge e;
    	e.to = b;
    	e.cost = c;
    	G[a].pb(e);
	}

	ll cost(int v){
		return d[v];
	}
};

int main(){
	int v,m;
    cin >> v;
    m = v-1;
    vector<int> color(v+1);
    
    dijkstra di(v,m);
    dijkstra di2(v,m);
    
    rep(i,0,m){
        int a,b;
        cin >> a >> b;

        di.addpath(a,b,1);
        di.addpath(b,a,1);
        di2.addpath(a,b,1);
        di2.addpath(b,a,1);
    }

    di.run(1);
    di2.run(v);

    color[1] = 1;
    color[v] = 2;
    
    int t = 0;
    stack<int> f,s;
    f.push(1);
    s.push(v);
    
    while(1){
        if(t&1){
            ll n = 0,cnt = 0;
            while(1){
                int ss = s.top();
               
                for(auto i:di.G[ss])if(color[i.to] == 0){
                    if(cnt == 0){
                        n = i.to;
                        cnt++;
                    }else if(di.cost(n) > di.cost(i.to)){
                        n = i.to;
                        cnt++;
                    }
                }

                if(cnt == 0){
                    s.pop();
                    if(s.empty()){
                        P("Fennec");
                        ret 0;
                    }else continue;
                }
                color[n] = 2;
                s.push(n);
              //  P(n);
                break;
            }
        }else{
            ll n = 0,cnt = 0;
            while(1){
                int ff = f.top();
                
                for(auto i:di2.G[ff])if(color[i.to] == 0){
                    if(cnt == 0){
                        n = i.to;
                        cnt++;
                    }else if(di2.cost(n) > di2.cost(i.to)){
                        n = i.to;
                        cnt++;
                    }
                }

                if(cnt == 0){
                    f.pop();
                    if(f.empty()){
                        P("Snuke");
                        ret 0;
                    }else continue;
                }
                color[n] = 1;
                f.push(n);
              //  P(n);
                break;
            }
        }
        t++;
    }
}
