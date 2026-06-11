#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	string s;
  	cin >> s;
    int A, Z;
  	for(int i = 0; i < s.size(); i++){
    	if(s[i] == 'A'){
        	A = i;
          	break;
        }
    }
  	for(int i = 0; i < s.size(); i++){
    	if(s[i] == 'Z'){
        	Z = i;
        }
    }
  	cout << Z - A + 1 << endl;
  	return 0;
}