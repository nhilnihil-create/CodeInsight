# include <bits/stdc++.h>
using namespace std;
int add(int x){
  if (x==0){
    return 0;
  }
  int sum=add(x-1);
  return sum+x;
}  
int main(){
  int N;
  cin >> N;
  cout << add(N) << endl;
}