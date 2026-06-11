#include<iostream>
#include<algorithm>

using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define LINT long long
int swap(int* x, int* y){
  int work = *x;
  *y=*x;
  *x=work;
}

int main(){
  int N;
  cin >> N;
  int p[N+1];
  for(int i = 1; i<N+1; ++i){
    cin >> p[i];
  }
  int count=0;

  for(int i = 1; i<N; ++i){
    if(p[i] == i){
      swap(&p[i], &p[i+1]);
        count += 1;
        ++i;
    }
  }
  if(p[N] == N){
    count += 1;
  }
  cout << count;
  return 0;
}
