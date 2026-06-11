#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;

  vector<int> v(N);  
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  int ans = 0;
  for(int i = 0; i < N-1; i++){
    int tmp = i+1;
    if(tmp == v[i]){
      ans++;
      v[i] = v[i+1];
      v[i+1] = tmp;
    }
  }

  if(v[N-1] == N){
    ans++;
  }
  cout << ans << endl;



}
