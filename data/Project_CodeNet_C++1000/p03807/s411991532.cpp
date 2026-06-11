#include <iostream>
#define ll long long
using namespace std;

ll arr[100005];
int main() {
  int n;
  cin >> n;

  int odd = 0;
  for (int i = 1; i <= n; i++){
    cin >> arr[i];
    ll f = arr[i];
    if (f%2 == 1){
      odd++;
    }
  }

  if (odd%2 == 1){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
  }
}