#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
  int N;
  long long a, b;
  cin >> N >> a >> b;
  int x[N];
  long long count = 0;
  
  for (int i = 0; i < N; ++i) {
  scanf("%d", &x[i]);
	}
  for (int i= 0; i< N-1; ++i){
    count += min(a*(x[i+1] -x[i]), b);
  }
  cout << count << endl;
}
  
  