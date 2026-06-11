#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int ar[n];
  int a;
  int sum=0;
  for(int i=0;i<n;i++){
     cin>>a;
    ar[i]=a;
    sum+=a;
  }
  int q;
  cin>>q;
  while(q--){
    int x,b;
    cin>>x>>b;
    int s;
    s=(sum-ar[x-1])+b;
    cout<<s<<endl;
  }
 return 0;
}