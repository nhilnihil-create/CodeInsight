#include <bits/stdc++.h>
using namespace std;
int main (){
	int k,s,r=0;
	cin >> k >> s;
	int x,y,z;
	for (int y=0;y<=k;y++){
		for (int z=0;z<=k;z++){
			int x = s-y-z;
			if (x <= k && x >= 0){
				r++;
			}
		}
	}	
	
	cout << r;
	
	
	return 0;
}