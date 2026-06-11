#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll hp[100005];
int n;
ll a, b;

int check(ll t){
  ll sum = 0;
  for(int i = 0; i < n; i++){
    if(hp[i] - (b * t) <= 0) continue;
    sum += (hp[i] - (b * t)) / (a - b);
    if((hp[i] - (b * t)) % (a - b) != 0) sum++; 
  }
  return sum <= t;
}

int main(){
  cin >> n >> a >> b;
  for(int i = 0; i < n; i++) cin >> hp[i];
  sort(hp, hp + n);
  ll left = 0, right = hp[n-1];
  while(right - left > 1){
    ll mid = (left + right) / 2;
    if(check(mid)) right = mid;
    else left = mid;
  }
  cout << right << endl;
  return 0;
}
