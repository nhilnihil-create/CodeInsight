#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int f;
int s;

queue<int> q;
int df[100010];
int ds[100010];
vector<vector<int>> edge(100010);

void dfs(){
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto x:edge[now]){
            if(df[x]==0){
                df[x]=df[now]+1;
                q.push(x);
            }
        }
    }
}
void dss(){
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto x:edge[now]){
            if(ds[x]==0){
                ds[x]=ds[now]+1;
                q.push(x);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    f=0;
    s=0;
    rep(i,n-1){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    fill(df,df+100010,0);
    fill(ds,ds+100010,0);
    q.push(0);
  	df[0]=1;
    dfs();
    q.push(n-1);
  	ds[n-1]=1;
    dss();
    int fen=0;
    rep(i,n){
        if(df[i]<=ds[i])fen++;
      	cerr << df[i] << ' ' << ds[i] << endl;
    }
    if(fen>=n/2+1)cout << "Fennec";
    else cout << "Snuke";


    
}