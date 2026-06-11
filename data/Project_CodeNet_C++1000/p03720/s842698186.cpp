#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int kotae[n];
  for(int i=0;i<n;i++)kotae[i]=0;
  for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    kotae[a]++;
    kotae[b]++;
  }
  for(int i=0;i<n;i++){
    cout<<kotae[i]<<endl;
  }
  return 0;
}