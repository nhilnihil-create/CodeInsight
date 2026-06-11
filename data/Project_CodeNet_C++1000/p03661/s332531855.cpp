#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;


int main(){
	long long N,ans=100000000000,x=0,y=0; cin >> N;
	long long a[N];
	for(int i=0; i<N; i++){
		cin >> a[i];
		x+=a[i];
	}for(int i=0; i<N-1; i++){
		y+=a[i];
		ans=min(ans,abs(x-2*y));
	}
	cout << ans << endl;
}