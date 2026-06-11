#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 998244353;
 
// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;
int vals[100001] = {0};
vector<int> graph[100001];
vector<int> opp[100001];
void dfs(int node){
    vector<int> v;
      for (int i : graph[node]){
          dfs(i);
          v.push_back(vals[i]);
      }
      sort(v.rbegin(), v.rend());
      int cnt = 0;
      for (int p : v){
          cnt++;
          vals[node] = max(vals[node], p+cnt);
      }
}
int main ()
{
  prep();
  int n;
  cin >> n;
  
  for (int i=2; i<=n; i++){
      int a;
      cin >>a;
      graph[a].push_back(i);
      opp[i].push_back(a);
  }
  
  int maxx = 0;
  
  dfs(1);
  for (int i=1; i<=n; i++){
      maxx = max(vals[i], maxx);
      //cout << vals[i] << " ";
  }
  cout << maxx;
  return 0; 
}