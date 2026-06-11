#include <bits/stdc++.h>

using namespace std;

int main(){
 	int x=0, max=0;
  	int n; cin >> n;
  	string s;
  	cin >> s;
  	for(char i:s){
     	if(i=='I')
          	x++;
     	else if(i=='D')
          	x--;
      	if(x>max) max=x;
    }
  	cout << max;
}