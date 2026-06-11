#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s, ans="No";
    cin >> s;
    for(int i=0; i<s.size(); i++)
      if(s[i]=='9'){
        ans = "Yes";
        break;
      }
    cout << ans << endl;

}