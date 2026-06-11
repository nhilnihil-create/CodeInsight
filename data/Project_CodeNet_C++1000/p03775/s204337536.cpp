#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

ll calculateDivNums(ll tg){
	ll ans = 0;
	for(ll a=1;a*a<=tg;a++){
      if(tg%a!=0){
        continue;
      }
      ll b = tg/a;
      ll tmp = max(a,b);
      if(a==1){
        ans = tmp;
      }else{
        ans = min(tmp,ans);
      }
    }
  return ans;
 }   

string S;
ll A,B,C,K,N, cnt;

int main(){
  cin >> N;
  ll ans = calculateDivNums(N);
  int dig = log10(ans)+1;
  printl(dig);
}
