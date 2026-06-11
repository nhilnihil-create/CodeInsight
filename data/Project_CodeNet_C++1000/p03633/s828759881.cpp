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


unsigned long euclidean_gcd(unsigned long a, unsigned long b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}


int main(void){
    unsigned long N;
    cin >> N;
    unsigned long neko;
    cin >> neko;
    for(long i =1;i < N ; i ++){
        unsigned long tmp;
        cin >> tmp;
        if(neko % tmp){
            neko = min (neko , tmp) * ( max (neko , tmp) / euclidean_gcd(neko,tmp));
        }
    }
    cout << neko << endl;
}