#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int x;
	cin >> x;
	int sum = 0;
	for(int i = 1 ; ; i ++){
		sum += i;
		if(x <= sum){
			printf("%d\n",i);
			return 0;
		}
	}
}