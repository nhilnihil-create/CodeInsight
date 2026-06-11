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
  int n,m,k;
  int x=0;
  cin>>n>>m>>k;
  for(int a=0;a<=n;a++){
    for(int b=0;b<=m;b++){
      if(a*b+(n-a)*(m-b)==k){
        x=1;
      }
    }
  }
  x==1?cout<<"Yes":cout<<"No";
}