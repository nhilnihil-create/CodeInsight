#include <bits/stdc++.h>
using namespace std;

set<int> digitos = {0,1,2,3,4,5,6,7,8,9};

bool notPossible(int n){
	while(n>0){
		if(!digitos.count(n%10)) return true;
		n /= 10;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n,k,x;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		digitos.erase(x);
	}
	while(notPossible(n)){
		n++;
	}
	cout << n << endl;
}
