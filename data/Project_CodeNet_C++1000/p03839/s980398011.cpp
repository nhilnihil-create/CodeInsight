#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
  
  cin >> N >> K;
  
    long long int a[100010];
  
   long long int s[100010]={0}, t[100010]={0};
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
      
        s[i+1] = s[i] + a[i];
        t[i+1] = t[i] + (a[i] >= 0 ? a[i] : 0);
    }
  
    long long res = -1e18;
    for (int i = 0; i + K <= N; ++i) {
        int left = i, right = i + K;
      
        long long tmp = (t[left] - t[0]) + max(0LL, s[right] - s[left]) + (t[N] - t[right]);
        res = max(res, tmp);
    }
    cout << res << endl;
}
