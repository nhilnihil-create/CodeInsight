#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,T;
  cin >> K >> T;
  vector<pair<int,int> > vp(T);
  for(int i=0;i<T;i++){
    int a;
    cin >> a;
    vp.at(i)=make_pair(a,i);
  }
  sort(vp.begin(),vp.end(),greater<pair<int,int> >());
  int ans=0;
  int pre=vp.at(0).second;
  vp.at(0).first--;
  if(vp.at(0).first==0){
    vp.erase(vp.begin());
  }
  if(vp.empty()){
    cout << ans << endl;
    return 0;
  }
  for(int i=0;;i++){
    bool flag=false;
    if(vp.empty()){
      break;
    }
    for(int j=0;j<vp.size();j++){
      if(vp.at(j).second!=pre){
        vp.at(j).first--;
        pre=vp.at(j).second;
        flag=true;
        if(vp.at(j).first==0){
          vp.erase(vp.begin()+j);
        }
        break;
      }
    }
    if(!flag){
      ans+=vp.front().first;
      break;
    }
    sort(vp.begin(),vp.end(),greater<pair<int,int> >());
  }
  cout << ans << endl;
  return 0;
}
