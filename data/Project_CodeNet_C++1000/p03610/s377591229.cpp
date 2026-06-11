#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
   	string s;	
  	cin >> s;
  	for(int i = 1; i <= s.length(); i++){
    	if(i % 2 == 1){
        	cout << s[i-1];
        }
    }
  	cout << endl;
    return 0;
}