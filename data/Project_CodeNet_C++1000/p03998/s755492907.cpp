#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
vector<string> vec(3);
  for(ll i=0;i<3;i++) {
cin>>vec[i];
  }
  
  reverse(all(vec[0]));
  reverse(all(vec[1]));
  reverse(all(vec[2]));
  
  
  ll turn =0;
  for(ll i=0;i<300;i++) {
    if(vec[turn].size()==0) {
cout<<(char)('A'+turn)<<endl;
      return 0;
    }
    char k=vec[turn].back();
    vec[turn].pop_back();
   turn=k-'a';
  }
}
    
    
   
    

  
