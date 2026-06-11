#include <iostream>

#define rep(n) for(int i = 0; i < n; i++)

using namespace std;

int main(void)
{
  int A, B, ans;

  cin >> A >> B;

  if((ans = A + B) >= 10)
    cout << "error" << endl;
  else
    cout << ans << endl;
  return 0;
}
