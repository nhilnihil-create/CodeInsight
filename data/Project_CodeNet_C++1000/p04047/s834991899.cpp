//In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;
#define nn '\n'
#define pb push_back
#define F(i, n) for(int i = 0; i < n; ++i)
#define Fe(i, n) for(auto i: n)
#define  ll long long int





int main(){

	int n; cin>>n;
	int arr[2 * n];
	F(i, 2 * n) cin>>arr[i];
	sort(arr, arr + 2 * n);
	int tot = 0;

	//F(i, 2 * n)
	for(int i = 0; i <2 * n; i += 2){
			tot += arr[i];
		}
	cout<<tot<<"\n";
	return 0;
	}
