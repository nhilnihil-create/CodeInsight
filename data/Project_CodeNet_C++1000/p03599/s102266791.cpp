#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  map<int,int> water;
  for(int i=0;i*100*a<=f;i++){//a増やすやつをi回やる
    for(int j=0;j*100*b<=f-i*a;j++){//b増やすやつをj回やる
      water[i*100*a+j*100*b] ++;
    }
  }
  map<int,int> sugar;
  for(int i=0;i*c<=f;i++){//c増やすやつをi回やる
    for(int j=0;j*d<=f-i*c;j++){//d増やすやつをj回やる
      sugar[i*c+j*d] ++;
    }
  }
  int ans1 = 0;
  int ans2 = 0;
  int dens = 0;
  for(auto w : water){
    for(auto s : sugar){
      int wat = w.first;
      int sug = s.first;
      if(wat + sug == 0) continue;
      if(wat + sug <= f && sug <= e*wat/100){
        double tmp = (double)10000*sug/(wat+sug);
        if(tmp >= dens){
          ans1 = wat + sug;
          ans2 = sug;
          dens = tmp;
          //cout << ans1 << " " << ans2 << " " << e*wat/100 << " " << dens << endl;
        }
      }
    }
  }
  cout << ans1 << " " << ans2 << endl;
}
