#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll=long long ;
int main(){
	long long n,i;
	cin >> n;
	for(i=1;n>0;i++)	n-=i;
	cout << i-1 << endl;
	return 0;
}
