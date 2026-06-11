#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sidha(i,a,b) for(int i=a;i<b;i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n;cin>>n;
	int a[n+1],b[n+1];
	memset(b,0,sizeof(b));
	for(int i=1;i<n+1;i++){
		cin>>a[i];
	}
	int c=0;
	for(int i=1;i<n+1;i++){
		if(b[i]==0){
			if(a[a[i]]==i){
				c++;
				b[i]=1;
				b[a[i]]=1;
			}
		}
	}
	cout<<c<<endl;
  return 0;
}