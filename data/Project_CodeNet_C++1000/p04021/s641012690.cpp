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
  int n,ans=0; cin>>n;
  int a[n],moto[n],zaatu[n];
  rep(i,n){
    cin>>a[i];
    moto[i]=a[i];
  }
  sort(a,a+n);
  map<int,int> mp;
  rep(i,n){
    mp[a[i]]=i;
  }
  rep(i,n){
    zaatu[i]=mp[moto[i]];
  }
  rep(i,n){
    int x=zaatu[i];
    if(x%2!=i%2){
      ans++;
    }
  }
  cout<<ans/2;
}
