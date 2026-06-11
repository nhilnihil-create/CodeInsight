#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	long long n, c, k;
	cin >>n >>c >>k;

	vector<long long> t(n);
	for(int i = 0; i < n; ++i)
		cin >>t[i];
	
	sort(begin(t), end(t));

	long long b = 0, cnt = 0, bt = 0;
	for(int i = 0; i < n; ++i){
		if(t[i] > bt || cnt == c){
			bt = t[i] + k;
			cnt = 1;
			++b;
		}
		else{
			++cnt;
		}
	}
	cout <<b <<'\n';
	return 0;
}
