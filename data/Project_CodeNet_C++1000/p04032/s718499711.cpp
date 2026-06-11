#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
  	rep(i, s.size() - 1){
      if(s[i] == s[i+1]){
        cout << i+1 << " " << i+2 << endl;
        return 0;
      }
    }
	rep(i, s.size() - 2){
      if(s[i] == s[i+2]){
        cout << i+1 << " " << i+3 << endl;
        return 0;
      }
    }
	cout << "-1 -1" << endl;
	return 0;
}
