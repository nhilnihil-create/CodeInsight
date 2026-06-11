#include<iostream>
using namespace std;
int main(){
  int N; 
  cin >> N;
  int x = 0;
  for(int i = 1; i <= N; i++){
    x += i;
  }
  cout << x << '\n';
}