#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

int main(){
  ll h, w, n; cin >> h >> w >> n;
  vector<pair<int, int> > SQ;
  for(int i=1;i<=n;i++){
    int a, b; cin >> a >> b;
    for(int ii=0;ii<=2;ii++){
      for(int jj=0;jj<=2;jj++){
        if((a-ii>=1 && b-jj>=1) && (a-ii+2<=h && b-jj+2<=w)){
          SQ.push_back(make_pair(a-ii, b-jj));
        }
      }
    }
  }
  sort(SQ.begin(), SQ.end());
  ll ans[10];
  for(int i=1;i<=9;i++) ans[i]=0;
  ll t=1, sum=0;
  for(int i=1;i<SQ.size();i++){
    if(SQ[i]==SQ[i-1]){
      t++;
    }else{
      ans[t]++;
      sum++;
      t=1;
    }
  }
  if(n >= 1){
    ans[t]++;
    sum++;
  }
  ans[0]=(h-2)*(w-2)-sum;
  for(int i=0;i<=9;i++) cout << ans[i] << endl;
}