#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()

int n,a[110];
bool ok[110];

bool find(int x,int w){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(ok[i]||a[i]!=x)continue;
		ok[i]=true;
		cnt++;
		if(cnt==w)break;
	}
	if(cnt!=w)return false;
	return true;
}

void input(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	return;
}

void solve(){
	sort(a,a+n);
	int mx=a[n-1];
	if(mx%2==0){
		for(int i=mx;i>=mx/2;i--){
			if(i==mx/2){
				if(!find(i,1)){
				cout<<"Impossible"<<endl;
				return;
				}
			}
			else {
				if(!(find(i,2))){
				cout<<"Impossible"<<endl;
				return;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(ok[i])continue;
			if(a[i]>mx/2&&a[i]<=mx)ok[i]=true;
			else{
				cout<<"Impossible"<<endl;
				return;
			}
		}
	}
	else{
		for(int i=mx;i>=(mx+1)/2;i--){
			if(!(find(i,2))){
				cout<<"Impossible"<<endl;
				return;
			}
		}
		for(int i=0;i<n;i++){
			if(ok[i])continue;
			if(a[i]>(mx+1)/2&&a[i]<=mx)ok[i]=true;
			else{
				cout<<"Impossible"<<endl;
				return;
			}
		}
	}
	cout<<"Possible"<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}