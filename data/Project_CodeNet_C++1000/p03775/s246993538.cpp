#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <math.h>

using namespace std;

int main() {
  long long N;
  cin >> N;

  int res;
  for(int i = 1; i <= sqrt(N); ++i){
    if(N % i == 0){
      if(N / i < i){
        res = i;
      }else{
        res = N / i;
      }
    }
  }
  string s = to_string(res);
  cout << s.size() << endl;
}

