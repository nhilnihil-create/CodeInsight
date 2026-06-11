#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
   string s;
   cin >> s;
   rep(i,s.size()){
      if(s[i] == ',' ) s[i] = ' ';
   }
   cout << s << endl;
   return 0;
   
}

