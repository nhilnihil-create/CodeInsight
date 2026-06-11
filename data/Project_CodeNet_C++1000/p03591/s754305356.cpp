#include<bits/stdc++.h>
 
#define INF 1000000007
#define LINF 1000000000000000007
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;


string s;

int main(){
	cin >> s;
	
	if(s.size() < 4){
		cout << "No" << endl;
		return 0;
	}
	string t = "YAKI";
	for(int i = 0; i < 4; i++){
		if(s[i] != t[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
	return 0;
}