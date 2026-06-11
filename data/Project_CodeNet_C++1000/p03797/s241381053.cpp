#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
	long long s,c;
	cin >> s >> c;
	long long cnt=0;
	cnt+=min(c/2,s);
	c-=2*cnt;
	cnt+=c/4;
	cout << cnt << endl;
	return 0;
}
