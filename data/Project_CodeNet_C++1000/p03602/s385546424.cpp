 #include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;

//https://beta.atcoder.jp/contests/arc083/tasks/arc083_b

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

//vector<int> v[10001];
//vector<int> v_old[10001];

/*
int ans(int k,int w){
  int i,ind,s=0;
  vector<int>::iterator m;
  if(v[w].size() <= k){
    return accumulate(v[w].begin(),v[w].end(),0);
  }
  REP(i,k){
    m = max_element(v[w].begin(),v[w].end());
    s += *m;
    ind = distance(v[w].begin(),m);
    v[w].erase(v[w].begin()+ind);
  }
  return s;
}
*/

LL mind[300][300];
LL mind_dum[300][300];
LL d[300][300];
LL min_gd[300][300];

int main(){
  int n;
  cin>>n;
  int i,j,k;
  LL tmp;
  REP(i,n){
    REP(j,n){
      cin >> tmp;
      mind[i][j]=tmp;
      min_gd[i][j]= tmp;
      d[i][j]= (i==j)?0:-1;
    }
  }
  REP(i,n){
    REP(j,n){
      REP(k,n){
	min_gd[i][j] = min(min_gd[i][j],min_gd[i][k]+min_gd[k][j]);
      }
    }
  }
  int bl=0;
  REP(i,n){
    REP(j,n){
      if(i>=j || bl)
	continue;
      if(min_gd[i][j] < mind[i][j])
	bl=1;
      if(min_gd[i][j] > mind[i][j])
	d[i][j] = mind[i][j];
      else{
	REP(k,n){
	  if(k != i && k != j && mind[i][j] == mind[i][k] + mind[k][j])
	    break;
	  if(k==n-1)
	    d[i][j]=mind[i][j];
	}
      }
      d[j][i] = d[i][j];
    }
    if(bl)
      break;
  }
  /*
    REP(i,n){
    REP(j,n){
    cout << d[i][j] << " ";
    }
    cout<<endl;
    }
  */
  LL ret=0;
  if(!bl){
    REP(i,n){
      REP(j,n){
	ret += (i < j && d[i][j] >= 0)? d[i][j]:0;
      }
    }
  }
  cout << (bl?-1:ret) << endl;
  return 0;
}
