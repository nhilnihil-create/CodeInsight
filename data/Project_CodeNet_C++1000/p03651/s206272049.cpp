#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  long long N, K;
  cin >> N >> K;
  priority_queue<long long, vector<long long>, greater<long long> > A;
  int flg=0;

  for (int i = 0; i < N; i++){
    long long tmp;
    cin >> tmp;
    A.push(tmp);
    if (tmp == K){
      printf("POSSIBLE\n");
      return 0;
    }
    if(tmp > K) flg = 1;
  }

  if (flg==0){
    printf("IMPOSSIBLE\n");
  }else{
    
    long long t;
    while (!A.empty() && A.top() != 1){
      t = A.top();
      A.pop();
      while (!A.empty() && A.top() % t == 0) A.pop();
      if (!A.empty()){
        A.push(A.top() % t);
      }
    }
    

    if (A.empty() && K%t!=0){
      printf("IMPOSSIBLE\n");
    }else{
      printf("POSSIBLE\n");
    }
    
  }
  
  
}
