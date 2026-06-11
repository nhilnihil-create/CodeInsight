#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
set<string> c;
map<ll,ll> mp;
const ll inf=100000000000000000;
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
int n,m;
vector<vector<int>> graph;
vector<bool> used;
vector<int> ans;
void dfs(int s){
 ans.push_back(s+1);
 used.at(s)=false;
 for(int i=0;i<graph.at(s).size();i++){
     int v=graph.at(s).at(i);
     if(used.at(v))return dfs(v);
 }
 return;
}

int main(){
 cin>>n>>m;
graph.resize(n);
used.resize(n);
for(int i=0;i<n;i++)used.at(i)=true;
for(int i=0;i<m;i++){
   int a,b;
   cin>>a>>b;
   a--;b--;
   graph.at(a).push_back(b);
   graph.at(b).push_back(a);
}
dfs(0);
reverse(ans.begin(),ans.end());
 ans.pop_back();
 dfs(0);
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans.at(i)<< " ";
    }
    cout << endl;
}
