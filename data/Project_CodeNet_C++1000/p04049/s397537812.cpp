#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

vector<int> gr[2000];
//葉方向に最も遠い点との距離
int dfs(int s, int p, int d){
  int res=d;
  rep(i,gr[s].size()){
    if(gr[s][i]!=p){
      res=max(res,dfs(gr[s][i],s,d+1));
    }
  }
  return res;
}

int main(){
  int n,k;
  cin >> n >> k;
  int a,b;
  int u[n-1],v[n-1];
  rep(i,n-1){
    cin >> a >> b;
    a--;b--;
    gr[a].pb(b);
    gr[b].pb(a);
    u[i]=a;v[i]=b;
  }
  int lm=0;
  /*  rep(i,n){    
    lm=max(dfs(i,-1,0),lm);
    }*/
  //  cout << lm << endl;
  int ans=INT_MAX;
  if(k%2==0){
    rep(i,n){
      queue<pair<pair<int, int >, int> > q;
      int c=0;
      q.push(mp(mp(-1,i),0));
      while(!q.empty()){
	int par=q.front().first.first;
	int cur=q.front().first.second;
	int d=q.front().second;

	q.pop();
	if(d>k/2) continue;
	//	cout << "cur " << cur << " dist " << d << endl;		
	c++;
	rep(j,gr[cur].size()){
	  if(gr[cur][j]!=par){
	    q.push(mp(mp(cur,gr[cur][j]),d+1));
	  }
	}
      }
      //      cout << i << " " << c << endl;
      ans = min(ans,n-c);      
    }
  }
  else{
    rep(i,n-1){
      queue<pair<pair<int, int >, int> > q;
      int c=0;
      q.push(mp(mp(u[i],v[i]),0));
      q.push(mp(mp(v[i],u[i]),0));
      //    cout << pt_can[i] << " " << endl;
      while(!q.empty()){
	int par=q.front().first.first;
	int cur=q.front().first.second;
	int d=q.front().second;
	q.pop();
	if(d>(k-1)/2) continue;
	c++;
	//      cout << "dep " << d << " pt " << cur << endl;
	rep(j,gr[cur].size()){
	  if(gr[cur][j]!=par){
	    q.push(mp(mp(cur,gr[cur][j]),d+1));
	  }
	}
      }
      //    cout << pt_can[i] << " " << c << endl;
      ans = min(ans,n-c);
    }    
  }
  
  cout << ans << endl;
  return 0;

}
