#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e15+4;
const int Nmax=2e5+1;
const int Nd=61;
ll dfs[3003][3003][4];
ll  v[3003][3003];


int main(){
  string x;// s=(, t=)に該当
  cin>>x;
  int n;
  n=x.size();
  int ph=0,now=0;//

  rep(i,n){
    //入れ子の何層目に相当するかを計算
    //s-> ph+=1;
    // t かつph>0 ->ph-=1;
    // t かつph<=0 -> now+=1;

    if(x[i]=='S'){
      ph++;
    }else{
      if(ph>0){
        ph--;
      }else{
        now++;
      }
    }
  }
  now+=ph;

  cout<<now<<endl;
}
