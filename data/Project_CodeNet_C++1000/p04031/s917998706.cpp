#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  int l, r=0, a[n];
  vector<int> list;
  int cost;
  while(cin>>l){
    a[r]=l;
    r++;
  }
  sort(a,a+n);
  
  for(int i = a[0]; i<=a[n-1]; i++){
    cost=0;
    for(int j=0; j<n; j++){
      cost=cost+pow(a[j]-i, 2);
    }
    list.push_back(cost);
  } 
  vector<int>::iterator iter = min_element(list.begin(), list.end());
  cout<<iter[0]<<endl;
}