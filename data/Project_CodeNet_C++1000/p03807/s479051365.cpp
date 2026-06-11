# include <iostream>
using namespace std;
int main(){

  int n;
  cin >> n;

  int sum = 0;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    sum += x;
    sum %= 2;
  }

  cout << (sum == 0 ? "YES" : "NO") << endl;
  return 0;
}