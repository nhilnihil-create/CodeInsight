#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  int n,m; cin>>n>>m;
  int x[m],y[m];
  rep(i,m){
    cin>>x[i]>>y[i];
    x[i]--; y[i]--;
  }
  int ball[n],possible[n]={};
  rep(i,n){
    ball[i]=1;
  }
  possible[0]=1;
  rep(i,m){
    ball[x[i]]--;
    ball[y[i]]++;
    if(possible[x[i]]==1){
      possible[y[i]]=1;
      if(ball[x[i]]==0){
        possible[x[i]]=0;
      }
    }
  }
  int ans=0;
  rep(i,n){
    if(possible[i]==1){
      ans++;
    }
  }
  cout<<ans;
}
