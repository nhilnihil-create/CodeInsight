#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int max_n = 1e6;
ll a[max_n];
int main(){
  ll n;  cin >> n;
  ll cnt4 = 0;
  ll cnt2 = 0;
  ll clu = 0;
  for(int i=0 ; i<n ; i++){
    cin >> a[i];
    if(a[i]%4==0 ) cnt4++;
    else if(a[i]%2==0) cnt2++;
    else clu++;
  }
  string s = "";
  if(clu+cnt2 %2-1 <= cnt4){
    s += "Yes";
  }else{
    s += "No";
  }
  cout << s << endl;
  return 0;
}
