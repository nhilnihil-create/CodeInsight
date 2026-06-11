#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int N; cin >> N;
  vector<int> a(3*N);
  for(int i = 0; i < 3*N; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int count = 0;
  long long ans = 0;
  for(int i = 3*N-2; i >= 0; i-= 2)
  {
    count++;
    ans += a[i];
    if(count == N) break;
  }
  cout << ans << endl;
}
