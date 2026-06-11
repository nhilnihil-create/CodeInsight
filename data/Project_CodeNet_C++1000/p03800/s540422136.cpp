#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  string ans = "-1";
  for(int i=0; i<4; ++i){
    string nans;
    if(i%2 == 0) nans += 'S';
    else nans += 'W';
    if((i>>1)%2 == 0) nans += 'S';
    else nans += 'W';
    for(int j=1; j<n-1; ++j){
      if((nans[j] == 'W' && s[j] == 'o') || (nans[j] == 'S' && s[j] == 'x')){
        nans += (nans[j-1] == 'S' ? 'W':'S');
      }else{
        nans += (nans[j-1] == 'S' ? 'S':'W');
      }
    }
    bool frag = true;
    if(nans[n-1] == 'W' && s[n-1] == 'o' && nans[0] == nans[n-2]) frag = false;
    else if(nans[n-1] == 'W' && s[n-1] == 'x' && nans[0] != nans[n-2]) frag = false;
    else if(nans[n-1] == 'S' && s[n-1] == 'o' && nans[0] != nans[n-2]) frag = false;
    else if(nans[n-1] == 'S' && s[n-1] == 'x' && nans[0] == nans[n-2]) frag = false;
    if(nans[0] == 'W' && s[0] == 'o' && nans[1] == nans[n-1]) frag = false;
    else if(nans[0] == 'W' && s[0] == 'x' && nans[1] != nans[n-1]) frag = false;
    else if(nans[0] == 'S' && s[0] == 'o' && nans[1] != nans[n-1]) frag = false;
    else if(nans[0] == 'S' && s[0] == 'x' && nans[1] == nans[n-1]) frag = false;
    if(frag){
      ans = nans;
      break;
    }
  }
  cout << ans << endl;
}