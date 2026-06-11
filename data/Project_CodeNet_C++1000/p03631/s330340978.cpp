//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
void isPalindrome(string str) 
{ 
	// Start from leftmost and rightmost corners of str 
	int l = 0; 
	int h = str.size() - 1; 

	// Keep comparing characters while they are same 
	while (h > l) 
	{ 
		if (str[l++] != str[h--]) 
		{ 
			cout<<"No"; 
			return; 
		} 
	} 
	cout<<"Yes"; 
} 
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	string s;
	cin>>s;
	isPalindrome(s);
	return 0;
}
