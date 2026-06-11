#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	string s;
	cin>>s;
	for(int i=1;i<s.length();++i){
		string t=s.substr(0,s.length()-i);
		if(t.length()%2!=0){
			continue;
		}
		if(t.substr(0,t.length()/2)==t.substr(t.length()/2)){
			cout<<t.length();return 0;
		}
	}
	cout<<s.length();
}