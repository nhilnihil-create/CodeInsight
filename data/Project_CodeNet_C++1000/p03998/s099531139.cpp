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
#include <numeric>
#include <math.h>
using namespace std;



int main(void){
  int N;

  string a,b,c;
  cin >> a >> b >> c;

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  reverse(c.begin(), c.end());

  char state = 'a';
  while(1){
    switch(state){
      case 'a':
        if(a.size() == 0){
          cout << "A" << endl;
          return 0;
        }
        state = *(a.end()-1);
        a.pop_back();
        break;
      case 'b':
        if(b.size() == 0){
          cout << "B" << endl;
          return 0;
        }
        state = *(b.end()-1);
        b.pop_back();
        break;
      case 'c':
        if(c.size() == 0){
          cout << "C" << endl;
          return 0;
        }
        state = *(c.end()-1);
        c.pop_back();
        break;
    }
  } 
  return 0;
}