#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	long long n, a, b;
	cin >>n >>a >>b;

	if(n == 1){
		if(a == b){
			cout <<"1\n";
		}
		else{
			cout<<"0\n";
		}
	}
	else{
		if(a > b){
			cout <<"0\n";
		}
		else{
			long long ans = (n - 2) * (b - a) + 1;
			cout <<ans <<'\n';
		}
	}

	return 0;
}
