#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long long n,m;
  cin >> n >> m;
  long long yoko=0,tate=0;
  long long now,next;
  long long shou = 1000000007;
  cin >> next;
  for(int i=1;i<=n-1;i++){
    now = next;
    cin >> next;
    yoko+=(((next-now)*(n-i)%shou)*i%shou);
    yoko%=shou;
  }
  cin >> next;
  for(int i=1;i<=m-1;i++){
    now = next;
    cin >> next;
    tate+=(((next-now)*(m-i)%shou)*i%shou);
    tate%=shou;
  }

  cout << (tate*yoko%shou) << endl;

  return 0;
}
