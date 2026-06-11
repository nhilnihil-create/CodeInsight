#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)

int main(){
  string S;
  cin>>S;
  
  int l=S.size();
  int num=1<<(l-1);
  int64_t results=0;
  rep(tmp, num){
    bitset<16> bits(tmp);
    
    int64_t t_sum=0, digit=1;
    // cout<<bits<<endl;
    
    rep(i, l){
      t_sum+=digit*(S[l-1-i]-'0');
      // cout<<i<<' '<<digit*(S[l-1-i]-'0')<<' '<<t_sum<<endl;
      digit = (bits[i]) ? 1 : digit*10;
    }
    // cout<<t_sum<<endl;
    results+=t_sum; 
  }
  cout<<results;
}