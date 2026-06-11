#include<iostream>
#include<set>
using namespace std;
int main(){
  int N;
  cin >> N;
  int a[N] = {};
  for(int i=0; i<N; i++) cin >> a[i];

  int flag = 0;
  int counter = 1;
  for(int i=0; i<N-1; i++){
    if(flag == 0 && a[i+1]-a[i] > 0) flag = 1;
    if(flag == 0 && a[i+1]-a[i] < 0) flag = -1;
    if(flag == 1){
      if(a[i+1]-a[i] < 0){
        counter++;
        flag = 0;
      }
    }
    if(flag == -1){
      if(a[i+1]-a[i] > 0){
        counter++;
        flag = 0;
      }
    }
  }
  cout << counter << endl;
  return 0;
}