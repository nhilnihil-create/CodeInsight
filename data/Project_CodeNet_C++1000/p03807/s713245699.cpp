#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);  
  int even=0, odd=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]%2) odd++;
    else even++;
  }
  if(odd%2) {
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  return 0;
}
