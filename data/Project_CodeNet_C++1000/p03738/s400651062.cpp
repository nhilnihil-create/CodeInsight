#include <bits/stdc++.h>
#define ll long long
#define Arman_Sykot ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
using namespace std;

int main()
{
/*********************/
// Author:
        Arman_Sykot;
/*********************/
    
	string a, b;
	cin >> a >> b;
	
	if (a.length() > b.length()) {
		cout << "GREATER" << "\n";
		return 0;
	}
	
	else if (a.length() < b.length()) {
		cout << "LESS" << "\n";
		return 0;
	}
	
	int num, num1;
	for (int i = 0; i < a.size(); i++) {
		num = a[i] - '0';
		num1 = b[i] - '0';
		
		if (num > num1) {
			cout << "GREATER" << "\n";
			return 0;
		}
		
		else if (num < num1) {
			cout << "LESS" << "\n";
			return 0;
		}
	}
	
	cout << "EQUAL" << "\n";
 
	
	return 0;
} 
