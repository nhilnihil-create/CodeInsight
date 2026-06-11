#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <regex>
#include <initializer_list>
#define DBL_MIN 0.000000000000001
#define A_P(n,a,d) (n/2)*(2*a + (n-1)*d)
using namespace std;

int main(void){
  string s;
  cin >> s;
  int last = -1;
  while(last != s.size() ){
    last = s.size();
    s = regex_replace(s,regex("WW"),"W");
    s = regex_replace(s,regex("BB"),"B");
  }

  cout << s.size()-1 << endl;
}