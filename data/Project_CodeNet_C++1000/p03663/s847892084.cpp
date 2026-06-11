//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int printi(ll val){
	char ch;
	cout<<"? "<<val<<endl;
	cin>>ch;
	if(ch=='Y')
		return 1;
	return 0;
}
ll haha[100],lol[100];
int doreg(){
	ll low=0;
	ll high=9;
	ll mid;
	ll ans=0;
	while(low<=high){
		mid=(low+high)/2;
		if(printi(haha[mid])){
			ans=mid;
			//cout<<mid<<endl;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	//cout<<ans<<endl;
	low=haha[ans];
	high=haha[ans+1]-1;
	while(low<=high){
		mid=(low+high)/2;
		if(printi(mid*10)){
			
			ans=mid;
			high=mid-1;
		}
		else{

			low=mid+1;
		}
	}
	cout<<"! "<<ans<<endl;
	return 0;

}
int brutecheck(){
	ll pres=9;
	//ll ans=1;
	ll i;
	rep(i,10){
		lol[i]=printi(pres);
		pres*=10;
		pres+=9;
	}

	rep(i,10){
		if(lol[i]==1)
			break;
	}
	cout<<"! "<<haha[i]<<endl;
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	ll inff=inf,i;
	inff-=5;
	inff*=10;
	haha[0]=1;
	f(i,1,11){
		haha[i]=haha[i-1]*10;
	}

	int val=printi(inff);     
    if(val==0){
    	doreg();
    	return 0;
    }
    else{
    	brutecheck();
    	return 0;
    }
}

