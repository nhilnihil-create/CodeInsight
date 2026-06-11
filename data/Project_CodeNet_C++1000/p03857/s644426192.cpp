#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
const int INF = 1 << 20;
#define MAXX 20010
typedef long long ll;



//int par[MAXX];
//初期化
void init(int n,int par[]){
  REP(i,n){
    par[i] = i;
  }
}
//根をもとめる
int root(int x, int par[]){
  if(par[x] == x){
    return x;
  }
  else{
    return par[x] = root(par[x],par);
  }
}

bool same(int x,int y,int par[]){
  if(root(x,par) == root(y,par)){
    return true;
  }
  else{
    return false;
  }
}

void unite(int x,int y, int par[]){
  x = root(x,par);
  y = root(y,par);
  if(x == y){
    return;
  }
  par[x] = y;
}

int main(){
  int n,k,l;
  cin >> n >> k >> l;
  int par[n+1];
  int parx[n+1];
  init(n+1,par);
  init(n+1,parx);
  REP(i,k){
    int p,q;
    cin >> p >> q;
    unite(p,q,par);
  }
  REP(i,n+1){
    root(i,par);
  }
  /*
  REP(i,n+1){
    cout << par[i] << endl;
    }*/
  REP(i,l){
    int p,q;
    cin >> p >> q;
    unite(p,q,parx);
  }
  REP(i,n+1){
    root(i,parx);
  }

  vector <P> pair;
  for(int i = 0;i < n+1;i++){
    
    pair.pb(mk(par[i],parx[i]));
    
  }
  sort(pair.begin(),pair.end());
  for(int i = 1;i < n+1;i++){
    int x = par[i];
    int y = parx[i];
    //iterator j = lower_bound(pair.begin(),pair.end(), make_pair(x,y)) ;
    //cout << j << endl;
    /*
    while(x != pair[j].first || y != pair[j].second){
      j++;
    }
    */
    //iterator k = upper_bound(pair.begin(),pair.end(), make_pair(x,y));
    /*
    while(x == pair[k].first && y == pair[k].second){
      k++;
      }*/
    cout << upper_bound(pair.begin(),pair.end(), make_pair(x,y)) - lower_bound(pair.begin(),pair.end(), make_pair(x,y)) << " " ;
  }
  cout << endl;
  /*
  int num[n+1]={0};
  for(int i = 1;i < n+1;i++){
    for(int j = i; j < n+1;j++){
      if(par[i] == par[j] && parx[i] == parx[j]){
	num[i]++;
	num[j]++;
      }
    }
  }
  for(int i = 1;i < n+1;i++)
    cout << num[i]-1 << " ";
  cout << endl;
  */
}
