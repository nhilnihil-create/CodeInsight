#include<iostream>
#include<set>

using namespace std;

int main(){
	long long x, y;
	cin >>x >>y;
	long long ans = 1e18, dist = 0;
	
	if(abs(x) == abs(y)){
		cout <<"1\n";
		return 0;
	}

	//BA
	if(-x < y){
		dist = y + x + 1;
		ans = min(ans, dist);
	}
	//AB
	if(x < -y){
		dist = -y - x + 1;
		ans = min(ans, dist);
	}
	//BA...AB
	if(-x < -y){
		dist = -y + x + 2;
		ans = min(ans, dist);
	}	
	//AAA..A
	if(x < y){
		dist = y - x;
		ans = min(ans, dist);
	}

	cout <<ans <<'\n';
	return 0;
}
