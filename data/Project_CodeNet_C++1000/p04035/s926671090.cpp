#include <iostream>
//#include <bits/stdc++.h>
// a&1 check odd or not and a>>=1 halfs a
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
#define ll long long
const int N=1e5+8;
int n;
ll arr[N];
ll joints[N];
ll l;

void solve(){	
	cin>>n>>l;
	loop(i,0,n){
		cin>>arr[i];
	}
	ll maxlen=-1;
	ll ind;
	loop(i,0,n-1){
		joints[i]=arr[i]+arr[i+1];
		if(maxlen<joints[i]){
			ind=i;
			maxlen=joints[i];
		}
	}	
	if(maxlen<l){
		cout<<"Impossible"<<endl;
//		puts("Impossible");		
	}
	else{
//		puts("Possible");
		cout<<"Possible"<<endl;
	if(ind==0){
		for(int i=n-2;i>=0;i--){
			cout<<i+1<<endl;
		}
	}
	else if(ind==n-2){
		for(int i=0;i<n-1;i++){
			cout<<i+1<<endl;
		}
	}
	else{
		for(int i=n-2;i>ind;i--){
			cout<<i+1<<endl;
		}
		for(int i=0;i<ind;i++){
			cout<<i+1<<endl;
		}
		cout<<ind+1<<endl;
	}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
	return 0;
}

