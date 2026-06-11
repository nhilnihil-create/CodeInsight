/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with(false); cin.tie(0);cout.tie(0);
const int MOD = 1000000007;
#define PI = acos(-1)
using namespace std ;
int a[106];
int main(){
    int n ; cin >> n ;
    map<int,int>mp;
    vector<int> v(n);
    for(int i  =0 ; i<n ; i++){
    	 cin >> v[i];
	}
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		 if(v[i]!= i+1){
		 	continue ;
		 }
		 else{
		 	swap(v[i] , v[i+1]);
		 	count++;
		 } 
	}
	cout << count << endl;
}