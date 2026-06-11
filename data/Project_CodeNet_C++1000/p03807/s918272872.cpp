#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;

  int num = 0;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    if(tmp %2 == 1) num++;
  }

  cout << (num % 2 == 0 ? "YES" : "NO") << endl;
}
