#include<bits/stdc++.h>
using namespace std;
#define maxn 220

int a[maxn],b[maxn];
int cnt,hh1,tt1,hh2,tt2,x[maxn];
long long n;

void init(){
	while ( n >= 1 ){
		if ( n == 2 ){ x[++cnt] = 1; break; }
		if ( n & 1 ) x[++cnt] = 1 , n--;
		else x[++cnt] = 2 , n >>= 1;
	}
}
int main(){
	cin>>n , n++;
	init();
	tt1 = hh1 = 100 , tt2 = hh2 = 100;
	for (int i = cnt ; i >= 1 ; i--){
		if ( x[i] == 1 ){
			a[--hh1] = i , b[tt2++] = i;
		}	
		else{
			a[tt1++] = i , b[tt2++] = i;
		}
	}
	cout<<tt1 - hh1 + tt2 - hh2<<endl;
	for (int i = hh1 ; i < tt1 ; i++) cout<<a[i]<<" ";
	for (int i = hh2 ; i < tt2 ; i++) cout<<b[i]<<" ";
	return 0;
}

