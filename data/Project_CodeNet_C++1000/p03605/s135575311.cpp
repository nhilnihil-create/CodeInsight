#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num,i,j;
	cin >> num;
	
	i = num/10;
	j = num%10;
	
	if(i == 9 || j == 9) cout << "Yes";
	else cout << "No";
	
	
	
}