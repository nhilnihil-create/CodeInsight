#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 	string s; getline(cin, s);
  	int start, end;
  	int i;
  	for(i=0;s[i]!='A';i++);
  	start=i;
  	for(i=start;i<s.size();i++){
    	if(s[i]=='Z')
        	end=i;
    }
  	cout << end-start+1;
}