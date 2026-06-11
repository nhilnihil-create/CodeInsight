#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  long long A[N];
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  sort(A, A+N);

  int ans=0;
  long long s=0;
  for (int i = 0; i < N-1; i++){
    s += A[i];
    if (s*2 >= A[i+1]){
      ans++;
    }else{
      ans=0;
    }
  }
  ans++;
  printf("%d\n",ans);
  
}
