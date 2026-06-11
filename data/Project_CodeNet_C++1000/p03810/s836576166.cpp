#include <bits/stdc++.h>

using namespace std;

int A[101010];
int n;

int gcd(int a, int b) { for(; a; swap(a, b)) b %= a; return b; }

bool check()
{
	int i, s1, s2, g;
	
	s1 = 0; s2 = 0;
	
	for(i=0; i<n; i++){
		s1 += (A[i] & 1);
		s2 += (A[i] == 1);
	}
	
	if(s1 + n & 1) return 1;
	else if(s1 != 1 || s1 == s2) return 0;
	else{
		g = 0;
		
		for(i=0; i<n; i++){
			if(A[i] & 1) A[i] --;
			g = gcd(g, A[i]);
		}
		
		for(i=0; i<n; i++){
			A[i] /= g;
		}
		
		return !check();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> A[i];
	}
	
	cout << (check()? "First" : "Second") << endl;
	
	return 0;
}