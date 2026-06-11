#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string o, e, s = "";
	cin >> o >> e;
  	int s_long = o.length() + e.length();
  	for(int i = 1; i <= s_long; i++){
    	if(i % 2 == 1){
        	s += o[i/2];
        }else{
        	s += e[(i/2)-1];
        }
    }
  	cout << s << endl;
    return 0;
}