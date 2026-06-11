#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int a,b,c,d;
   string s;
   cin >> a >> b >> c >> d;
   cout << max(a*b,c*d) << endl;


   return 0;
}

