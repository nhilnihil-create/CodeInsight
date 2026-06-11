#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<math.h>
#include<bitset>
#include<random>
#include<cstdint>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(17)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<char,P> Q;
ll longinf=(1ll<<60);

int N,M;
vector<int> v[100000];
vector<int> tree[100000];
bool visited[100000];
vector<int> ans;
bool ok=true;
void dfs(int i){
      for(auto node:v[i]){
            if(!visited[node]){
                  ans.push_back(node);
                  visited[node]=true;
                  dfs(node);
            }
            int mochi=v[i].size()-1;
            if(node==v[i][mochi]) ok=false;
            if(!ok){
                  break;
            }
      }
}
int main(){
      cin>>N>>M;
      rep0(i,M){
            int A,B;
            cin>>A>>B;
            A--;B--;
            v[A].push_back(B);
            v[B].push_back(A);
      }
      ans.push_back(0);
      visited[0]=true;
      dfs(0);
      reverse(ans.begin(),ans.end());
      ok=true;
      dfs(0);
      cout<<ans.size()<<endl;
      for(auto a:ans){
            cout<<a+1<<" ";
      }
      cout<<endl;
      
      return 0;
}