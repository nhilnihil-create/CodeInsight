#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=1; i<=10000; i++){
    int sum=i*(i+1)/2;
    int x=i;
    if(sum>=n){
      for(int j=1; j<=x; j++){
        if(j==sum-n)continue;
        cout<<j<<endl;
      }
      return 0;
    }
  }
}
  