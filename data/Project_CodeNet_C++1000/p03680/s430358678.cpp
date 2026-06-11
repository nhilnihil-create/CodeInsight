#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int a[N+1];
  for(int i=0; i<N; i++)
    cin >> a[i+1];
  //

  bool pushed[N+1];
  for(int i=0; i<N+1; i++)
    pushed[i] = false;

  int count = 0;
  int now = 1;
  pushed[now] = true;
  while(1){
    if(a[now] == 2){
      cout << count+1 << endl;
      return 0;
    }
    if(pushed[a[now] ] == false){
      pushed[a[now] ] = true;
      now = a[now];
      count++;
    }
    else{
      cout << -1 << endl;
      return 0;
    }
  }

  
  
  return 0;
}
