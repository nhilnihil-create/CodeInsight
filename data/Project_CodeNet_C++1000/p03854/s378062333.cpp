#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,tmp;
  	cin >> s;
  	int len = s.length();
  	int No(0);
  	for(int i  = len-1;;){
        if(i == -1){
        cout << "YES";
        return 0;
      }else if(i <= 2){
          cout << "NO";
          return 0;
        }
      if(s.at(i) == 'e'){
       	tmp = s.substr(i-4,5);
        	if(tmp == "erase"){
        	i = i - 5;
           }
      }else if(s.at(i) == 'r'&&s.at(i-1) == 'e'&& s.at(i-2) == 's'){
        tmp = s.substr(i-5,6);
			if(tmp == "eraser"){
        	i = i - 6;
            }
      }else if(s.at(i) == 'm'){
        tmp = s.substr(i-4,5);
        if(tmp =="dream"){
        	i = i - 5;
        	}
      }else if(s.at(i) == 'r'&&s.at(i-1) == 'e'&& s.at(i-2) == 'm'){
       	tmp = s.substr(i - 6,7);
      	if(tmp == "dreamer"){
        	i = i - 7;
        }
      }
      
      if(i == No){
        cout << "NO";
        return 0;
      }
      No = i;
    }
  
}
