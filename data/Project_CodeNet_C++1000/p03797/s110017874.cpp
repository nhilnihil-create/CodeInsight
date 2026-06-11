#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define LL long long int

int main(int argc, char** argv) {
    LL n,m,sum;
	cin>>n>>m;//n==s m==c
	if(n>=m) cout<<m/2<<endl;
	else {
		sum=n;
		m=m-(n*2);
		sum+=m/4;
		cout<<sum<<endl;
	}
    return 0;
}
