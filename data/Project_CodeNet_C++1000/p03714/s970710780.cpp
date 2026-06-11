#include<bits/stdc++.h>
#define randome_generate srand(std::chrono::high_resolution_clock::now().time_since_epoch().count())
using namespace std;
#define fmax akioi
multiset<long long> fmax,foth,bmin; 
multiset<long long>::iterator it;
int n;
long long a[300100];
long long b[200100];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=3*n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*2;i++){
		b[i]=a[i];
	}
	sort(b+1,b+n*2+1);
	reverse(b+1,b+n*2+1);
	long long sigmaf=0LL,sigmab=0LL;
	for(int i=1;i<=n;i++){
		fmax.insert(b[i]);
		sigmaf+=b[i];
	}
	for(int i=n+1;i<=n*2;i++)
		foth.insert(b[i]);
	for(int i=n*2+1;i<=n*3;i++){
		bmin.insert(a[i]);
		sigmab+=a[i];
	}
	long long tmp;
	long long res=sigmaf-sigmab;
	for(int i=n*2;i>=n+1;i--){//delete
		it=foth.find(a[i]);
		if(it!=foth.end()){
			foth.erase(it);
		}
		else{
			it=fmax.find(a[i]);
			sigmaf-=*it; 
			fmax.erase(it);
			it=foth.find(*foth.rbegin());
			sigmaf+=*it;
			fmax.insert(*it);
			foth.erase(it);
		}
		if(a[i]<*bmin.rbegin()){
			it=bmin.find(*bmin.rbegin());
			sigmab-=*it;
			bmin.erase(it);
			sigmab+=a[i];
			bmin.insert(a[i]);
		}
		res=max(res,sigmaf-sigmab);
	}
	cout<<res<<endl;
	return 0;
}
