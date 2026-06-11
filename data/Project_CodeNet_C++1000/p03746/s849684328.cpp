#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include<tuple>
using namespace std;
#define INF 1LL<<62
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
//typedef pair<pair<int,int>,int> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

int C[110000];
vector<int> V[110000],ans,ans2;


void dfs(int x,int q){
    if(q==1) ans.push_back(x);
    else ans2.push_back(x);
    C[x]=1;
    bool flag=true;
    int nx;
    for(int next:V[x]){
        if(C[next]==0){
            flag=false;
            nx=next;
        }
    }
    if(flag) return;
    else dfs(nx,q);
}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(1,1);
    dfs(1,2);
    cout<<(int)ans.size()+(int)ans2.size()-1<<endl;
    reverse(ans2.begin(),ans2.end());
    for(int i=0;i<(int)ans2.size();i++){
        if(i) cout<<" ";
        cout<<ans2[i];
    }

    for(int i=1;i<(int)ans.size();i++){
        cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}
