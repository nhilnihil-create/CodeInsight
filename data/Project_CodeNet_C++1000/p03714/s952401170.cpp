#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n*3);
  for(int i = 0;i < n*3;i++)cin >> a[i];
  ll res = -1 * pow(10,18);
  ll nowf = 0;
  ll nowe = 0;
  priority_queue<ll> f;
  priority_queue<ll> e;
  vector<ll> maxf(n+1);
  vector<ll> maxe(n+1);
  
  for(int i = 0;i < n;i++){//前処理
    f.push(a[i] * -1);
    nowf += a[i];
  }
  maxf[0] = nowf;
  for(int i = 0;i < n;i++){
    nowf += a[i + n];
    f.push(a[i + n] * -1);
    nowf -= f.top() * -1;
    f.pop();
    maxf[i + 1] = nowf;
  }
  
  for(int i = 0;i < n;i++){//前処理
    e.push(a[3*n - i - 1]);
    nowe += a[3*n - i - 1];
  }
  maxe[n] = nowe;
  for(int i = 0;i < n;i++){
    nowe += a[2*n - i - 1];
    e.push(a[2*n - i - 1]);
    nowe -= e.top();
    e.pop();
    maxe[n - i - 1] = nowe;
  }
  
  for(int i = 0;i < n + 1;i++){
    res = max(res,maxf[i] - maxe[i]);
    //cout << maxf[i] << " " << maxe[i] << endl;
  }
  cout << res << endl;
}