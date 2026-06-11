#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  string s;
  cin >> s;

  rep(i,s.length()){
    rep(j,s.length()-i-1){
      if(s[i]==s[s.length()-j-1]){
	cout << "no" << endl;
	return 0;
      }
    }
  }

  cout << "yes" << endl;
}
