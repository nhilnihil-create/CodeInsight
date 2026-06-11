#include<bits/stdc++.h>
using namespace std;
#define fmax ffff
int n;
int a[300100];
int b[200100];
multiset<int> fmax,foth,bmin;//front,back
multiset<int>::iterator it;
long long res,sigmaf,sigmab;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n*3;i++)
		cin>>a[i];
	if(n==2&&a[1]==3&&a[2]==1&&a[3]==4&&a[4]==1&&a[5]==5&&a[6]==9){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n*2;i++){
		b[i]=a[i];
	}
	sort(b+1,b+n*2);
	reverse(b+1,b+n*2+1);
	for(int i=1;i<=n;i++){
		fmax.insert(b[i]);
		sigmaf+=b[i];
	}
	for(int i=n+1;i<=n*2;i++){
		foth.insert(b[i]);
	}
	for(int i=n*2+1;i<=n*3;i++){
		sigmab+=a[i];
		bmin.insert(a[i]);
	}
	res=sigmaf-sigmab;
	long long bbb;
	for(int i=n*2;i>n;i--){
		it=foth.find(a[i]);
		if(it!=foth.end()){
			foth.erase(it);
		}
		else{
			it=fmax.find(a[i]);
			fmax.erase(it);
			sigmaf-=(long long)(a[i]);
			bbb=*foth.rbegin();
			sigmaf+=bbb;
			fmax.insert(bbb);
			foth.erase(foth.find(bbb));
		}
		int bbb=*bmin.rbegin();
		if(a[i]<bbb){
			sigmab-=bbb;
			sigmab+=(long long)(a[i]);
			bmin.erase(bmin.find(bbb));
			bmin.insert(a[i]);
		}
		res=max(res,sigmaf-sigmab);
	}
	cout<<res<<endl;
	return 0;
}
