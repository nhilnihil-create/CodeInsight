#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

int main(){
	int w,a,b;
	cin >> w >> a >> b;
	int ans;
	if(abs(a-b)<=w){
		cout << "0" << endl;
		return 0;
	}else{
		cout << min(abs(b-(a+w)),abs(a-(b+w))) << endl;
		return 0;
	}
	return 0;
	
}
