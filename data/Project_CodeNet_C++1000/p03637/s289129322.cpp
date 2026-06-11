#include<bits/stdc++.h>

using namespace std;

int n, a[100000];
int two, four, none;

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] % 4 == 0) four++;
		else if(a[i] % 2 == 0) two++;
		else none++;
	}
	if(four+1 >= none && two == 0) cout << "Yes" << endl;
	else if(four >= none) cout << "Yes" << endl;
	else cout << "No" << endl;
}
