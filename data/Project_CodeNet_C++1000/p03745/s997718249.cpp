#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,a,prev;
	cin >> n;
	cin >> prev;
	int count = 1;
	bool increasing = false, decreasing =false;
	for(int i = 1;i<n;i++){
		cin >> a;
		if(a>=prev && increasing) {prev=a;}
		else if(a<=prev && decreasing) { prev=a;}
		else if(a<prev && increasing) {count++; prev=a; increasing=false; continue;}
		else if(a>prev && decreasing) {count++; prev=a; decreasing = false; continue;}
		else if(a>prev) {increasing = true; prev=a;}
		else if (a<prev) {decreasing = true; prev=a;}
	}
	cout << count;
			
		
}
