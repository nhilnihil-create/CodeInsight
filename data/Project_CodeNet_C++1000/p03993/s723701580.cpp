#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;


ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
bool root(string s){
    int n=s.length();
    if(n==2){
        if(s[0]==s[1]){
            return true;
        }
        else return false;
    }
    if(n==3){
        if(s[0]==s[2]){
            return true;
        }
        else return false;
    }
 
    return false;
}
 
 
//深さ優先
vector<int> seen;
vector<ll> h;
 
//普通の深さ優先探索seenを返す感じ
void dfs(const Graph &G,int v){
    seen[v] = 0; //v探索済み
 
    P good=make_pair(v,h[v]);
    for(auto next_v :G[v]){
        if(seen[next_v]!=-1) continue;//もう探索していた
        if(h[next_v]>good.second){
            good=make_pair(next_v,h[next_v]);
        }
        dfs(G,next_v);
    }
 
    if(!(h[v]==good.second && v==good.first)){
        seen[good.first]=1;
    }
}
 
signed main(){
    /*
    int n,m;
    cin>>n>>m;
 
    h.assign(n,0);
    rep(i,0,n) cin>>h[i];
 
    Graph G(n);
    rep(i,0,m){
        int a,b; cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
 
    seen.assign(n,-1);
 
    rep(i,0,n){
        if(seen[i]==-1){
            dfs(G,i);
        }
    }
 
    int sum=accumulate(all(seen),0);
 
    cout<<sum<<endl;*/
 
    int n;
    cin>>n;
    set<int> se;
    int a[n];
    rep(i,0,n){
        int ai;
        cin>>ai;
        a[i]=ai-1;
        //se.insert(i);
    }

    int ans=0;

    for(int i=0;i<n;i++){
        if(a[a[i]]==i){
            if(se.count(i)==0){
            ans++;
            se.insert(i);
            se.insert(a[i]);
            }
        }
    }
    

    cout<<ans<<endl;
}   