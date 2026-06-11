#include<iostream>
using namespace std;
int main(){
  long long n,rm_num,rm_cnt,sum_stone=0;
  cin >> n;
  int a[n],dif[n];
  bool f=false;
  rm_num=(n*(n+1))/2;
  cin >> a[0];
  sum_stone+=a[0];
  for(int i=0;i<n-1;i++){
    cin >> a[i+1];
    dif[i] = a[i+1]- a[i];
    sum_stone+=a[i+1];
  }
  dif[n-1] = a[0]-a[n-1];
  rm_cnt = sum_stone/rm_num;
  if(rm_cnt*rm_num!=sum_stone){
    cout <<"NO\n";
    return 0;
  }
  for(int i=0;i<n;i++){
      dif[i]-=rm_cnt;
    }
    for(int i=0;i<n;i++){
      while(dif[i]<0){
        dif[i]+=n;
      }
      if(dif[i]!=0){
        f=true;
        break;
      }
    }
    if(f) cout<<"NO\n";
    else cout <<"YES\n";

}
