#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int i = 1;
	while((i*2)<=n){
		//if(i>=n) break;
		i = i*2;
	}
	cout << i << endl;
	return 0;
}
