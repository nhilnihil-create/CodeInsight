#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int i, k, s, j, p, t=0;
	cin >> k;
	cin >> s;
	for (i = 0; i <= k; i++) {
		for (j = 0; j <= k; j++) {
				if (s-(i+j)<=k&&s-(i+j)>=0){
					t++;
				}
			}
		}
	cout << t << endl;
	return 0;
}