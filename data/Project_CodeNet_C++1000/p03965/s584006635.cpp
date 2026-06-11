#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;

int main() {
  string s; cin >>s;
  int len = s.size();
  int cnt_p_i = len/2;
  int cnt_p =0;
  for(int i=0;i<len;++i){
    auto sub = s.substr(i,1);
    if(sub=="p") ++cnt_p;
  }
  cout << cnt_p_i - cnt_p << endl;

  return 0;
}
