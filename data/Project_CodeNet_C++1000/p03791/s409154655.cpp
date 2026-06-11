#include<bits/stdc++.h>
#define int long long int
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VP;
typedef pair<PII, int> PPI;
const int INF = 3e18;

int n, x[100010], nx[100010];
int fast[100010];
int ans = 1;
signed main()
{
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> x[i];
  }

  int stock = 1, pre = 1;
  for(int i = 1; i < n; i++){
    if(pre + 1 == x[i]){
      stock++;
      ans *= stock;
      ans %= 1000000007;
      stock--;
    }
    else{
      stock++;
      pre += 2;
    }
  }

  while(stock){
    ans *= stock;
    ans %= 1000000007;
    stock--;
  }
  /*
  int next = 1;
  for(int i = 0; i < n; i++){
    if(x[i] >= next){
      x[i] = next;
      next += 2;
    }
    else{
      next += 1;
    }
  }

  int nownum = 1;
  nx[0] = 1;
  for(int i = 1; i < n; i++){
    nx[i] = nownum;
    if(x[i - 1] + 1 == x[i]){
      i++;
      nownum++;
      nx[i] = nownum;
    }
  }

  for(int i = 0; i < n; i++)
    fast[nx[i]]++;
  
  int kurikoshi = 0;
  for(int i = 1; i == 1 || kurikoshi; i++){
    kurikoshi += fast[i];
    ans *= kurikoshi;
    cout << kurikoshi << endl;;
    ans %= 1000000007;
    kurikoshi--;
  }
  
  for(int i = 0; i < n; i++){
    cout << i << ":" << x[i] <<endl;
  }
  for(int i = 1; i <= n; i++){
    cout << i << ":" << fast[i] <<endl;
  }
  */
  cout << ans << endl;
  return 0;
}
