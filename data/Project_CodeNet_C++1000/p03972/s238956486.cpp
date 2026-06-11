#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define PN() {cout << "No" << endl; return 0;}
#define PY() {cout << "Yes" << endl; return 0;}

int main(){
  long long int h,w; cin >> h >> w;
  vector<pair<long long int,int>> a(h+w);
  for(int i=0;i<h;i++){
  	int t;
    cin >> t;
    a[i].first = t; a[i].second = 0;
  }
  for(int i=h;i<h+w;i++){
  	int t;
    cin >> t;
    a[i].first = t; a[i].second = 1;
  }
  sort(a.begin(), a.end());
  long long int ans = 0;
  h++; w++;
  for(auto x: a){
  	int wa = x.first;
    if(x.second == 0){ans = ans + w*wa; h--;}
    else if(x.second == 1){ans = ans + h*wa; w--;}
    if(h==1 && w==1) break;
  }
  cout << ans << endl;
  return 0;
}