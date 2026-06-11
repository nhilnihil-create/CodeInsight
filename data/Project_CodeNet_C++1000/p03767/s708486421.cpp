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
  for(int i = 0; i < 3*N; i++){
    cin >> v.at(i);
  }
  sort(v.rbegin(), v.rend());
  ll sum = 0;
  int num = 0;
  int index = 1;
  while(true){
    sum += v.at(index);
    index += 2;
    num++;
    if(num == N) break;
  }
  cout << sum << endl;
}
