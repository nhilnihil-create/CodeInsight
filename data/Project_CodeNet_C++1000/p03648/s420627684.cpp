#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    long long k,n;
    cin>>k;
    n=k/50,k%=50;
    cout<<50<<endl;
    for(int i=1;i<=50;i++) {
	if(i<=k) cout<<100+n-k<<' ';
	else cout<<49+n-k<<' ';
    }
    return 0;
}