#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
#include<sstream>
#include<istream>
#include<numeric>
#include<stdlib.h>

using namespace std;

int main()
{

  int a, b, c;
  cin >> a >> b >> c;

  int cnt = 0;
  if(a != b){
    cnt++;
  }
  if(a != c){
    cnt++;
  }
  if(b != c){
    cnt++;
  }

  if(cnt == 0){
    cnt = 1;
  }

  cout << cnt << endl;

  return 0;
}
