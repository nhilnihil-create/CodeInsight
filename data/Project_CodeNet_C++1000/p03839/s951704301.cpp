#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll pref1[100050];
ll pref2[100050];
int niz[100050];

int n,k;

void input(){
	cin>>n>>k;
	int br;
	
	for(int i=1;i<=n;i++){
		cin>>br;
		niz[i]=br;
		if(i==0){
			pref1[i]=br;
			if(br>=0)pref2[i]=br;
		}
		else{
			pref1[i]=pref1[i-1]+br;
			pref2[i]=pref2[i-1];
			if(br>=0)pref2[i]+=br;
		}
		
	}
}

int main(){
	input();
	
	ll maxx1=-1000000000000000000;
	ll maxx2=-1000000000000000000;
	for(int i=1;i<=n-k+1;i++){
		ll raz1=pref1[i+k-1]-pref1[i-1];
		ll raz2=pref2[i+k-1]-pref2[i-1];
		
		ll raz3=0-raz2;
		ll raz4=raz1-raz2;
		
		maxx1=max(maxx1,raz3);
		maxx2=max(maxx2,raz4);
	}
	
	cout<<max(maxx1,maxx2)+pref2[n];
	
	
	
	return 0;
}