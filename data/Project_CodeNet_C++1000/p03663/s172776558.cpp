#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

char ans;

LL x;

inline void query(LL n){
  cout << "? " << n << endl;
  cin >> ans;
  // printf("? %d\n",n);
  // scanf("%c",&ans);
  // if((n<=x&&to_string(n)<=to_string(x))||(n>x&&to_string(n)>to_string(x))) ans='Y';
  // else ans='N';
  return;
}

int main(){
  // cin >> x;
  LL c=1;
  LL ketasu=-1;
  for(LL i=1;i<=11;i++,c*=10){
    query(c);
    if(ans=='N'){
      ketasu=i-1;
      break;
    }
  }
  // cout << ketasu << endl;
  LL l,r;
  LL kakutei=0;
  if(ketasu>1){
    for(LL i=1;i<ketasu;i++){
      l=0;r=10;
      while(r-l>1){
        query(kakutei*10+(l+r)/2);
        if(ans=='Y') l=(l+r)/2;
        else r=(l+r)/2;
      }
      kakutei=kakutei*10+l;
    }
    // cout << kakutei << endl;
    for(LL i=0;i<10;i++){
      query(kakutei*100+i*10);
      if(ans=='Y'){
        cout << "! " << kakutei*10+i << endl;
        return 0;
      }
    }
    return 0;
  }else if(ketasu==1){
    for(LL i=1;i<10;i++){
      query(i*10);
      if(ans=='Y'){
        cout << "! " << kakutei*10+i << endl;
        return 0;
      }
    }
  }else{
    c=1;
    for(LL i=1;i<=11;i++,c*=10){
      query(2*c);
      if(ans=='Y'){
        cout << "! " << c << endl;
        return 0;
      }
    }
  }
  return 0;
}
