#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    c+=a[i]%2;
  }
  cout<<(c%2==0?"YES":"NO")<<endl;
}