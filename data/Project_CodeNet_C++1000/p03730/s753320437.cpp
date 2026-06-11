#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> numb;
	int i = 2;
	numb.push_back(a%b);
	numb.push_back(-1);
	while(numb[numb.size()-1] != numb[0]){
		numb.push_back((a*i)%b);
		++i;
	}
	bool found = false;
	for(int j = 1; j < (int)numb.size(); ++j){
		if(numb[j] == c) {
			found = true;
			break;
		}
	}
	if(found) cout << "YES";
	else cout << "NO";
	return 0;
}

