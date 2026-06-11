#include <iostream>
using namespace std;

long long int n, x, cvp;
pair<long long int, long long int> paralel;

int main(){
	cin>>n>>x;
	cvp=n;
	paralel=make_pair(max(n-x, x) , min(n-x, x));
	while(paralel.second!=paralel.first&&paralel.second!=0){
		cvp+= 2*(paralel.first/paralel.second)*paralel.second;
		if(paralel.first%paralel.second==0)cvp-= paralel.second;
		paralel=make_pair(max(paralel.second, paralel.first - paralel.second*(paralel.first/paralel.second)) , min(paralel.second, paralel.first - paralel.second*(paralel.first/paralel.second)));
		if(paralel.second==1){
			cvp+= paralel.first *2 -2 ;
			paralel.second=1;
			break;
		}
	}
	cvp+=paralel.second;
	cout<<cvp;
	return 0;
}
