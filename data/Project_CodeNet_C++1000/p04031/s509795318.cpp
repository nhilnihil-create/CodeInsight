#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n,0);
  int min_cost=1001001;
  for(int i=0;i<n;i++){
     cin>>a[i];
  }
  for(int i=-100;i<=100;i++){
    int cost=0;
    for(int j=0;j<n;j++){
      int re=i-a[j];
      cost+=pow(re,2);
    }
    min_cost=min(min_cost,cost);
  }
  cout<<min_cost<<endl;
  return 0;
}
