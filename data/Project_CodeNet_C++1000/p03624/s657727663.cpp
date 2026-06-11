#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int len = s.size();
	for(char c = 'a';c <= 'z';c++){
		int ju = 0;
		for(int i = 0;i < len;i++){
			if(s[i] == c){
                ju = 1;
                break;
            }
		}
		if(!ju){
			cout << c << endl;
			return 0;
		}
	}
    cout << "None" << endl;
}