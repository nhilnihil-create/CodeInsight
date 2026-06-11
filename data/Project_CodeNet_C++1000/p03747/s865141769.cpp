#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	
	int n,l,t; cin >> n >> l >> t;
	vector<int> x(n), w(n);
	int aci=-1, cc=0;
	for(int i=0;i<n;i++){
		cin >> x[i] >> w[i];
		if(w[i]==2)
			aci=i;
		else
			cc++;
	}
	
	if(aci==-1 || cc==0){
		for(int i=0;i<n;i++){
			cout << ((x[i]+t*((w[i]==2)?-1:1))%l+l)%l << endl;
		}
		return 0;
	}
	
	
	vector<int> pot(n);
	for(int i=0;i<n;i++){
		if(w[i]==1){
			pot[i]=(1ll*x[i]+2*t)%l;
		}
		else{
			pot[i]=x[i];
		}
	}
	sort(pot.begin(),pot.end());
	
	int tot=2*t, fi=aci;
	long long nc=1ll*cc*(tot/l);
	
	tot%=l;
	
	for(int i=(aci-1+n)%n;i!=aci;i=(i-1+n)%n){
		if(w[i]==1){
			if(tot>=(x[aci]-x[i]+l)%l){
				nc++;
			}
			else{
				break;
			}
		}
	}
	nc%=n;
	while(nc--){
		fi=(fi-1+n)%n;
	}
	
	int st;
	for(int i=0;i<n;i++){
		if(pot[i]==x[aci]){
			st=i;
			break;
		}
	}
	
	vector<int> ans(n);
	for(int i=fi;;){
		ans[i]=pot[st];
		st=(st+1)%n;
		i=(i+1)%n;
		if(i==fi)
			break;
	}
	
	for(auto v:ans){
		cout << ((v-t+l)%l+l)%l << endl;
	}
	
	return 0;
}