#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
const int maxn = 1e6+7;

int main() {
	int n;
	cin>>n;
	ll *a=new ll[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	ll select=0,remain=0;
	ll min=1000000;
	select+=a[0];
	for(int k=1; k<n; k++) {
		remain+=a[k];
	}
	min = abs(select-remain);
	for(int i=1; i<n-1; i++) {
		select+=a[i];
		remain-=a[i];
		if(abs(select-remain)<min) {
			min=abs(select-remain);
		}
	}
	cout<<min<<endl;
	return 0;
}