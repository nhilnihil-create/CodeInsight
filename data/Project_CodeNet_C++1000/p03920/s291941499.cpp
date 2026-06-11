#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin>>n;
  int sum=0;
  int i=0;
  do{
    sum+=i;
    i++;
  }while(sum<=n);
  int div = sum - n;
  for(int k=1;k<i;++k){
    if(k==div) continue;
    cout << k<<endl;
  }
return 0;
}