#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int a,b;
  cin >> a >> b;
  if (a <= 0 && b >= 0) cout << "Zero" << endl;
  else if (a > 0 && b > 0) cout << "Positive" << endl;
  else if (a < 0 && b < 0){
    if ((abs(a)-abs(b)+1)%2 == 1) cout << "Negative" << endl;
    else cout << "Positive" << endl;
    //cout << (abs(a)-abs(b)+1) << endl;
  }
  return 0;
  
}
