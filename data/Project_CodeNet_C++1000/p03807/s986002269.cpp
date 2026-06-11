#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  long long saisho;
  cin >>saisho;
  long long sum=0;
  for(int i=1;i<n;i++){
    int a;
    cin>>a;
    sum+=a;
  }
  if(saisho%2==sum%2){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}