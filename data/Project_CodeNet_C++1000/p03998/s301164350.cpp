#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  vector<queue<char>> vec(3);
  rep(i, 3){
    string str;
    cin >> str;
    rep(j, str.length()){
      vec[i].push(str[j]);
    }
  }
  int current = 0;
  while(!vec[current].empty()){
    char c = vec[current].front();
    vec[current].pop();
    if(c == 'a') current = 0;
    else if(c == 'b') current = 1;
    else current = 2;
  }
  if(current == 0) cout << "A" << endl;
  else if(current == 1) cout << "B" << endl;
  else cout << "C" << endl;
  return 0;
}
  
  