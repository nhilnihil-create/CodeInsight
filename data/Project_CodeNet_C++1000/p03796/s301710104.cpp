#include <bits/stdc++.h>
using namespace std;
long long a=1;
int main(){
  long long N;
  cin >> N;
  for(long long i=1; i<=N; i++){
    a = a*i%1000000007;
  }
  cout << a << endl;
}
