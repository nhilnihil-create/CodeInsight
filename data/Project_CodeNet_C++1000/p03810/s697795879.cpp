#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<LL> a(n);
  int ki=0;
  LL total=0;
  int pos;
  bool one=false;
  for(int i=0;i<n;i++){
    cin >> a[i];
    total+=a[i]-1;
    if(a[i]%2){
      pos=i;
      ki++;
    }
    if(a[i]==1) one=true;
  }
  if(n==1){
    cout << "Second" << endl;
    return 0;
  }
  LL kaisu=1;
  int gcd,x,y;
  while(1){
    if(one){
      cout << (((kaisu+total)%2)?"Second":"First") << endl;
      return 0;
    }
    if(total%2){
      cout << (kaisu%2?"First":"Second") << endl;
      return 0;
    }
    if(ki>1){
      cout << (kaisu%2?"Second":"First") << endl;
      return 0;
    }
    kaisu++;
    a[pos]--;
    gcd=a[0];
    for(int i=1;i<n;i++){
      x=gcd;
      y=a[i]%gcd;
      if(y==0) continue;
      while(x%y){
        gcd=x;
        x=y;
        y=gcd%y;
      }
      gcd=y;
    }
    ki=0;
    total=0;
    for(int i=0;i<n;i++){
      a[i]/=gcd;
      total+=a[i]-1;
      if(a[i]%2){
        ki++;
        pos=i;
      }
      if(a[i]==1) one=true;
    }
    // for(int i=0;i<n;i++) cout << a[i] << " ";
    // cout << endl;
  }
  return 0;
}
