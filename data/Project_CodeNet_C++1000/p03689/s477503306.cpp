#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H,W,h,w;
  cin >> H >> W >> h >> w;
  int ele=1e3;
  if(H%h==0 && W%w==0){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  rep(i,H){
    rep(j,W){
      if(i%h==h-1 && j%w==w-1){
	cout << -(ele*(h*w-1)+1) << " ";
      }
      else {
	cout << ele << " ";
      }
    }
    cout << "" << endl;
  }






    
  return 0;
    

}
