#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	string s;
	cin >> s;

	string sr = s;
	reverse(all(sr));
	string t;
	for(auto i : sr){
		if(i == 'b'){
			t += 'd';
		}else if(i == 'd'){
			t += 'b';
		}else if(i == 'p'){
			t += 'q';
		}else if(i == 'q'){
			t += 'p';
		}else{
			t += i;
		}
	}

	cout << (s == t ? "Yes" : "No") << endl;
}
