#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s.size()%2==1){
  	cout << "No" << endl;
  	return 0;
  }
  for(int i=0;i<s.size()/2;i++){
  	if(s[i]=='p'){
  	  if(s[s.size()-1-i]!='q'){
  	  	cout << "No" << endl;
  	  	return 0;
  	  }
  	}else if(s[i]=='q'){
  	  if(s[s.size()-1-i]!='p'){
  		cout << "No" << endl;
  		return 0;
  	  }
  	}else if(s[i]=='b'){
  	  if(s[s.size()-1-i]!='d'){
  		cout << "No" << endl;
  		return 0;
  	  }
  	}else if(s[i]=='d'){
  	  if(s[s.size()-1-i]!='b'){
  		cout << "No" << endl;
  		return 0;
  	  }
  	}
  }
  cout << "Yes" << endl;
  return 0;
}