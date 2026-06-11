#include <iostream>
#include <climits>
using namespace std;

int main() {

  /*
  min → nilai terkecil dari array
  max → nilai terbesar dari array
  freqMin → berapa kali min muncul
  freqMax → berapa kali max muncul


  kalo min == max ?
    freqMin == n-1 → yes
    freqMin*2 <= → yes
    else → no

  kalo max == min+1 ?
    freqMin <= min dan max <= freqMin + freqMax/2 → yes
    else → no

  else → no
  */

  int n, num[100005];
  cin >> n;

  int mx = 0, mn = INT_MAX;
  for(int i=0; i<n; i++){
    cin >> num[i];
    mx = max(mx, num[i]);
    mn = min(mn, num[i]);
  }

  int freqMin = 0, freqMax = 0;
  for(int i=0; i<n; i++){
    if(num[i] == mx) freqMax++;
    if(num[i] == mn) freqMin++;
  }

  if(mn == mx){
    if(mn == n-1 || mn*2 <= n) cout << "Yes";
    else cout << "No";
  }
  else if(mn+1 == mx){
    if(freqMin <= mn && mx <= freqMin+freqMax/2) cout << "Yes";
    else cout << "No";
  }
  else cout << "No";
  cout << endl;
  return 0;
}