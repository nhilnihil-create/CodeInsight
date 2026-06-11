#include <bits/stdc++.h>
using namespace std;

long long func(long long X){
  return log10(X)+1;
}
    
int main() {
  long long min_F=100000000;
  long long N;
  cin >> N;
  for(int i=1;i<=sqrt(N);i++){
    if(N%i!=0){
      continue;
    }
    long long A=max((long long)i,N/i);
    long long F=func(A);
    min_F=min(min_F,F);
  }
  cout << min_F << endl;
} 