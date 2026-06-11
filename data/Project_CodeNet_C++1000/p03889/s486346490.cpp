#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i=0; i<n; i++)
const ll MOD=1e9+7;

int main(){

	string s, t, u;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[s.size()-i-1]=='b'){
			t.push_back('d');
		} else if(s[s.size()-i-1]=='d'){
			t.push_back('b');
		} else if(s[s.size()-i-1]=='p'){
			t.push_back('q');
		} else {
			t.push_back('p');
		}
	}
	if(s==t){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
