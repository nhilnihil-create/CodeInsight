#include <bits/stdc++.h>

using namespace std;

int main(){
 long h,w,n;
   cin >> h >> w >> n;

 map<pair<long,long>,long> mp;
  for(int k=0;k<n;k++) {
    long a,b;
    cin >> a >> b;
    a--;
    b--;
    for(int i=0;i<3&&a-i>=0;i++){
      for(int j=0;j<3&&b-j>=0;j++) mp[make_pair(a-i,b-j)]++;
     
      }
  }
    
  vector<long> num(10,0);
  num[0]=(h-2)*(w-2);
  for(auto m:mp){
    if(m.first.first>=h-2||m.first.second>=w-2) continue;
   num[m.second]++;
    num[0]--;
  }
  

  for(auto v:num) cout << v << endl;
}