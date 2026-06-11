#include <iostream>
using namespace std;
int main(){
  int n,a,result=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a;
    if(a%2==1) result++;
  }
  cout << (result%2==0 ? "YES" : "NO") << endl;
  return 0;
}