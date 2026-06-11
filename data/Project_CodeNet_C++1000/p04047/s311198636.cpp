#include <iostream>
//#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define F first
#define S second
using namespace std;
const int N=101;
int arr[2*N];
int n;

void solve(){
	scanf("%d",&n);
	loop(i,0,2*n){
		scanf("%d",&arr[i]);
	}
	int sum=0;
	sort(arr,arr+2*n);
	for(int i=2*n-2;i>=0;i=i-2){
		sum+=arr[i];
	}
	cout<<sum;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();



	return 0;
}


