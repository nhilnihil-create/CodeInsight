#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

bool k = false;
void str(string sa,string sb, string sc, char key) {
  if (key == 'a') {
    if(sa.empty()) k = true; else { key = sa[0]; sa.erase(0,1);  }
  } else if (key == 'b') {
    if(sb.empty()) k = true; else {key = sb[0]; sb.erase(0,1);  } 
  } else {
    if(sc.empty()) k = true; else {key = sc[0]; sc.erase(0,1);  } 
  }
  if (k) {
    key = key - 32;
    cout << key << endl;
  }else {
    str(sa,sb,sc,key);
  }
}
int main(void) {
  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  str(sa,sb,sc,'a');
}