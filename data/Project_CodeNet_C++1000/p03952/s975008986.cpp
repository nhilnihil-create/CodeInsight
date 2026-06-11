#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll x,n;
  ll tmp;
  cin>> n >> x;
  if(x==1||x==2*n-1){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for(int i=0;i<2*n-1;i++){
    if(i<n-1){
      tmp = x-(n-1-i);
      if(tmp<=0) tmp += 2*n-1;
    }else{
      tmp = x+(-n+1+i);
      if(tmp>2*n-1) tmp-=2*n-1;
    }
    cout << tmp<<endl;
  }
}
