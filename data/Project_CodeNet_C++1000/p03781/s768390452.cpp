#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x, sum=0;
	cin >> x;
	for(long long i=0; i<999999999; i++){
		sum += i;
		if(sum >= x){
			cout << i;
			return 0;
		}
	}
    return 0;
}
