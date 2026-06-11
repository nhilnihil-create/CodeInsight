#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
	long long x;
	cin >> x;
	long long cnt=2*(x/11);
	if(1<=x%11 && x%11<=6){
		cnt++;
	}else if(x%11>=7){
		cnt+=2;
	}
	cout << cnt << endl;
	return 0;
}
