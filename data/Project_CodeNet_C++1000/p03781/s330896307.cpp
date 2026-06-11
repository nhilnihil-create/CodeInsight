#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n,c=0;
  cin>>n;
  for(int i=1;;i++){
    c+=i;
    if(c>=n){
      cout<<i;
      return 0;
    }
  }
}
