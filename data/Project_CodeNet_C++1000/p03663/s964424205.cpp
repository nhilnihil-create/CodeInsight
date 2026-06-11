#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll ten[11];

void query(ll n){
    cout<<"? "<<n<<endl;
}

bool answer(){
    char c;
    cin>>c;
    if(c=='Y') return true;
    else return false;
}

int main(){
  ten[0]=1;
  for(int i=1;i<=10;i++) ten[i]=ten[i-1]*10;

  query(ten[10]);
  if(answer()){
      int it=0;
      for(int i=9;i>=1;i--){
          query(ten[i]-1);
          if(answer()==false){
              it=i;
              break;
          }
      }
      cout<<"! "<<ten[it]<<endl;
      return 0;
  }

  int digit=1;
  for(int i=1;i<=9;i++){
      query(ten[i]);
      if(answer()) digit++;
      else break;
  }

  ll ans=0;
  for(int d=1;d<=digit;d++){
      if(d==digit){
        int ok=9,ng=-1;
        while(abs(ok-ng)>1){
            int mid=(ok+ng)/2;
            ll res=ans*10+mid;
            res*=1e9;
            query(res);
            if(answer()) ok=mid;
            else ng=mid;
        }
        ans=ans*10+ok;
      }else{
        int ok=0,ng=10;
        if(d==1) ok=1;
        while(abs(ok-ng)>1){
            int mid=(ok+ng)/2;
            ll res=ans*10+mid;
            query(res);
            if(answer()) ok=mid;
            else ng=mid;
        }
        ans=ans*10+ok;
      }
  }
  cout<<"! "<<ans<<endl;

  return 0;
}
