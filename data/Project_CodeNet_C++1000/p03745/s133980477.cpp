# include <iostream>
using namespace std;

const int asc = -1;
const int dsc = 1;
const int rnd = 0;

int main(){

  int n, ans = 1;
  cin >> n;

  int a[n+3];
  for(int i=0; i<n; i++) cin >> a[i];

  int now = rnd;
  for(int i=0; i<n-1; i++){
    if((now == dsc && a[i] < a[i+1]) || (now == asc && a[i] > a[i+1])){
      ans++;
      now = rnd;
    }
    else if(a[i] > a[i+1]) now = dsc;
    else if(a[i] < a[i+1]) now = asc;
  }

  cout << ans << endl;
  return 0;
}