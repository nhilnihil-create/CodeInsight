#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
typedef long long ll;


int main(){
  string s;
  cin >> s;
  vector<char> v = {'W', 'S', 'N', 'E'};
  map<char, int> mp;
  rep(i, 4){
    mp[v[i]] = 0;
  }
  rep(i, s.size()){
    mp[s[i]]++;
  }
  bool flag = true;
  if(mp['S'] != 0 || mp['N'] != 0){
    if(mp['S'] == 0 || mp['N'] == 0){
      flag = false;
    }
  }

  bool flag2 = true;
  if(mp['W'] != 0 || mp['E'] != 0){
    if(mp['W'] == 0 || mp['E'] == 0){
      flag2 = false;
    }
  }

  if(flag && flag2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}

