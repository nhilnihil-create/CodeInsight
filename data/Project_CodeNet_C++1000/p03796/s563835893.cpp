#include <iostream>
using namespace std;
int MOD = 1000000007;

int main()
{
  int a;
  cin >> a;
  long long int sum = 1;
  for(int i = 1;i<=a;i++){
    sum = (sum*i)%MOD;
  }
  cout << sum << endl;
}
