#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  
  vector<char> d(k);
  for(int i=0;i<k;i++)
    cin >> d.at(i);
  
  for(int ans=n;ans<n*10;ans++){
    string s=to_string(ans);
    bool jg=false;
    for(auto x:d){
      if(s.find(x)!=-1)
        break;
      if(x==d.at(d.size()-1)){
        jg=true;
        break;
      }
    }
    if(jg){
      cout << ans << endl;
      return 0;
    }
  }
}
