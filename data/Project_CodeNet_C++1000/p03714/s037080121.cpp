#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<ll> v(3*N);
  ll sum = 0;
  priority_queue<ll,vector<ll>, greater<ll>> q1;
  priority_queue<ll> q2;

  for(int i = 0; i < 3*N; i++){
    cin >> v[i];
  }

  vector<ll> v1(N+1,0);
  vector<ll> v2(N+1,0);

  ll max_val = 0;
  for(int i = 0; i < 2*N; i++){
    if(i < N - 1 ){
      q1.push(v[i]);
      max_val += v[i];
    } else if(i == N-1){
      q1.push(v[i]);
      max_val += v[i];
      v1[0] = max_val;
    } else {
      ll tmp = q1.top();
      if(tmp < v[i]){
        q1.pop();
        q1.push(v[i]);
        max_val -= tmp;
        max_val += v[i];
      }

      v1[i-N+1] = max_val;
    }
  }

  ll min_val = 0;
  for(int i = 3*N-1; i >= N; i--){
    if(i >= 2 * N){
      min_val += v[i];
      q2.push(v[i]);

      if(i == 2 * N){
        v2[N] = min_val;
      }
    } else { 
      ll tmp = q2.top();
      if(tmp > v[i]){
        min_val -= tmp;
        min_val += v[i];
        q2.pop();
        q2.push(v[i]);
      }

      v2[i - N] = min_val;
    }
  }

  ll ans = -1000000000000000000;

  for(int i = 0; i <= N; i++){
    ll tmp = 0;
    tmp = v1[i] - v2[i];
    ans = max(ans, tmp);
  }
  cout << ans << endl;


}
