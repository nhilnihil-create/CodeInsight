#include <iostream>
using namespace std;
int main() {
	long long k,p,q,a;
	cin>>k;
	p=k/50;
	q=k%50;
	cout<<50<<endl;
	for(int i=1;i<=49;i++){
	    a=p-q+48;
	    if(i<=q){
	        a+=51;
	    }
	    cout<<a<<" ";
	}
	cout<<p-q+49<<endl;
	return 0;
}