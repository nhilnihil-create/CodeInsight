#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,k;
	cin>>n>>k;
	vector<int>D(k);
	for(int i=0;i<k;i++){
		cin>>D[i];
	}
	int ok=0;
	for(long long i=n;;i++){
		long long t = i;
		while(t){
			long long a = t%10;
			t=t/10;
			for(int j=0;j<k;j++){
				if(a==D[j]){
					ok=1;
					break;
				}
			}
			if(ok){
				break;
			}
		}
		if(!ok){
			cout<<i<<endl;
			break;
		}else{
			ok=0;
		}
	}
}
