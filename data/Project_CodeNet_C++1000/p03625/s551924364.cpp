#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int64_t n;
  cin>>n;

  map<int64_t , int64_t, greater<int64_t>> a;
  for(int i=0;i<n;i++){
    int64_t wk;
    cin>>wk;

    if(a.count(wk))
      a.at(wk)++;
    else
      a[wk]=1;
  }

  // 大きい順に確認
  int64_t side1=0,side2=0;
  bool found=false;
  for (auto p : a) {
    auto k = p.first;
    auto v = p.second;

    if(v/2>=2 && found==false){
      side1=k;
      side2=k;
      break;
    }else if(v/2>=1 && found==false){
      side1=k;
      found=true;
    }else if(v/2>=1 && found==true){
      side2=k;
      break;
    }
  }

  if(side1==0 && side2==0)
    cout<<0<<endl;
  else
    cout<<side1*side2<<endl;

	return 0;
}