#include <bits/stdc++.h>
using namespace std;

int main() {				
  string AtC,s,Con,Ans;					// *constarint*
  cin >> AtC >> s >> Con;		    // 1 <= s <= 100
  							        //1文字目は大文字2文字目以降小文字
  Ans += AtC.at(0);
  Ans += s.at(0);
  Ans += Con.at(0);
  cout << Ans << endl;
}
