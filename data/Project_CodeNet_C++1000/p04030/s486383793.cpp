#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  string ans;
  
  for(int i = 0 ; i < s.size() ; i++){
  	if(s.at(i)=='0'){
      ans += '0';
    }else if(s.at(i)=='1'){
      ans += '1';
    }else if(s.at(i)=='B'&ans.size()!=0){
      ans.pop_back();
    }
  		//cout << i << " : " <<  ans << endl; 
  }
	
  cout << ans << endl;
}
