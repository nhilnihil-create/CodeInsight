#include <iostream>
#include <cmath>

using namespace std;

int main(){
  long long N;
  cin >> N;
  int ans = (int)log10(N)+1;

  for (long long i = 1; i * i <= N; i++){
    if (N%i != 0) continue;
    long long M = N/i;
    int tmp=max((int)log10(i)+1, (int)log10(M)+1);
    if(ans > tmp) ans = tmp;
  }
  printf("%d\n",ans);
}
