#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  long long a, b;
  cin >> a >> b;
  long long cnt = 0;
  if(a * 2 <= b){
    cnt += a;
    b -= 2 * a;
    a = 0;

    cnt += b / 4;
  }
  else{
    cnt = b / 2;
  }
  cout << cnt << endl;

}       