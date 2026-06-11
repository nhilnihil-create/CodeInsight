#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105];
    int main(){
    	ll n,m,x=0,y=0; cin>>n>>m;
    	for (int i=1;i<=m;i++){
    		cin>>a[i];
    		if (a[i]&1){
    			if (!x)     x=i;
    			else if(!y) y=i;
    			else return cout<<"Impossible\n",0;
    		}
    	}
    	if (x) swap(a[1],a[x]);
    	if (y) swap(a[y],a[m]);
    	for(int i=1;i<=m;i++) cout<<a[i]<<' ';
    	m+=(m==1);
    	a[1]--, a[m]++;
    	int j=(a[1]?1:2);
    	cout<<endl<<' '<<m-j+1<<endl;
    	for (int i=j;i<=m;i++) cout<<a[i]<<' ';
		return 0;
    }
