#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<int >    vecint;
typedef vector<vector<int> >  vec2int;
typedef vector<ll >     vecll;
typedef vector<string > vecstr;
typedef vector<bool > vecbool;
typedef vector<bool > vecbool;
////////////////////////////////////////////////
int main()
{
  int n; cin >> n;
  unordered_map<int, int >mp;
  vecint a(n,0);
  int tmp;
  int num = 0;
  REP(i,n){
    cin >> tmp;
    a[i] = tmp;
    mp[tmp]++;
    if(mp[tmp] > 1){
      num ++;
    }
  }
  // sort(all(a));
  // REP(i,n){
  //   cout << a[i] << endl;
  // }
  // cout << num << endl;
  cout << n - 2*((num + 1)/2) << endl;

}