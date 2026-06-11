//in the name of god
//if you read this code please search about imam hussain
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define endl "\n"
#define X first
#define Y second
#define pii pair<int,int>
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)

const int maxn=1e5+5;
const int mod=1e9+7;
const int inf=1e9;
const int del=728729;

ll poww(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));}
ll n ;
ll l ;
ll arr[maxn];
ll tol[maxn];
ll mx=-1;
ll ind;
int main(){
	migmig;
	cin >> n >> l;
	for(int i = 1 ; i <= n ; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n-1 ; i ++){
		tol[i]=arr[i]+arr[i+1];
	}
	for(int i = 1 ; i <= n - 1 ; i++){
		if(tol[i]>mx){
			mx=tol[i];
			ind=i;
		}
	}
	if(mx >= l){
		cout<<"Possible"<<endl;
		for(int i = 1 ; i <= ind-1;i++){
			cout<<i<<endl;
		}
		for(int i = n - 1   ; i >= ind+1 ;i--){
			cout<<i<<endl;
		}
		cout<<ind;
	}else cout<<"Impossible";
	return 0;
}

