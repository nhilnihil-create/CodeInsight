#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<map>
using namespace std;
typedef unsigned long long int  ull;


int main(){
	ull c[100] ;
	for(int i=0;i<100;++i) c[i] = 0;
	string s;
	cin >> s;
	ull res = s.size()*(s.size()-1)/2 + 1;
	for(int i=0;i<s.size();++i){
		int index = s[i] -'a';
		c[index]++;
	}
	
	for(int i=0;i<100;++i){
		res -= c[i]*(c[i]-1)/2;
	}
	
	cout << res <<endl;
	
	
	return 0;
}
