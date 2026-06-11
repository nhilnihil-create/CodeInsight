#include<iostream>

using namespace std;

int main(){
  int N, ans=1;
  cin >> N;
  while((ans * 2) <= N){
    ans *= 2;
  }
  printf("%d\n",ans);
}
