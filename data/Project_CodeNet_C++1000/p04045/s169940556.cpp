#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,k,dd;
  cin>>n>>k;
  vector<int> d(10,0);
  for(int i=0;i<k;i++){
    cin>>dd;
    d[dd]=1;
  }
  for(int i=n;i<100000;i++){
    int flag=1;
    int tmp=i;
    while(tmp!=0){
       if(d[tmp%10]==1){
         flag=0;
         break;
       }
      tmp/=10;
    }
    if(flag){
      cout<<i<<endl;
       break;
    }
  }
  return 0;
  
}
