#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const int MAX_V=1e5+1;
vector<int> G[MAX_V];
int dis[2][MAX_V];
int used[2][MAX_V];
int c[2]={1,1};
void add_edge(int from, int to){
  G[from].pb(to);
  G[to].pb(from);
}
void distance(int s,int p, int d){
  rep(i,G[s].size()){
    int point = G[s][i];
    if(!used[p][point]){
      used[p][point]=1;
      dis[p][point]=d+1;
      distance(point, p, d+1);
    }
  }  
}

void search(int s, int p, int kinshi,int N){
  
  //  if(s!=kinshi){
  rep(i,G[s].size()){
    int point = G[s][i];
    if(!used[p][point] && point != kinshi){
      if(p==0 && point==N-1){
	continue;
      }
      else{
      used[p][point]=1;
      c[p]++;
      search(point,p,kinshi,N);
      }
    }
  }
  //  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int a,b;
  rep(i,N-1){
    cin >> a >> b;
    a--;
    b--;
    add_edge(a,b);
  }
  memset(used[0],0,sizeof(used[0]));
  memset(used[1],0,sizeof(used[1]));
  dis[1][N-1]=0;
  dis[0][0]=0;
  used[1][N-1]=1;
  used[0][0]=1;
  distance(N-1, 1, 0);
  distance(0, 0, 0);
  int l=INT_MAX;
  int index;
  rep(i,N){
    //    cout << i<<" : F Dis " << dis[0][i] << " S Dis " << dis[1][i] << endl;
    if(dis[0][i] == dis[1][i]){
      if(l > dis[0][i]){
	l = dis[0][i];
	index =i;
      }
    }

    if(dis[0][i]+1 == dis[1][i]){
      if(l > dis[0][i]){
        l = dis[0][i];
      	index =i;
      }
    }
  }
  //  cout << "kinshi " << index << endl;
  if(index!=0) c[0]=2;
  memset(used[0],0,sizeof(used[0]));
  memset(used[1],0,sizeof(used[1]));
  used[0][0]=1;
  used[1][N-1]=1;
  //  search(0, 0, index,N);
  search(N-1,1,index,N);
  c[0]=N-c[1];
  //  cout << "first pc : " << c[0] << " second pc : "<< c[1] << endl;
  if(c[0] <= c[1]){
    cout << "Snuke" << endl;
  }
  else{
    cout << "Fennec" << endl;
  }
  
  return 0;
    

}
