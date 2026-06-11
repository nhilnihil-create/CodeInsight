#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>//"geometry.cpp"
using namespace std;
#define pb push_back//Can be used for STRING
#define fi first
#define sc second
#define mp make_pair
#define is insert
typedef pair<int,int> pii;//Add other types in the same way.

const int n=50;

int main(){
	long long k,a[50];
	cin>>k;
	for(int i=0;i<n;++i) a[i]=(k/50)+i;
	k%=50;
	for(int i=0;i<k;++i){
		a[i]+=n;
		for(int j=0;j<n;++j) if(i!=j) a[j]-=1;
	}
	cout<<n<<endl;
	for(int i=0;i<n;++i) cout<<a[i]<<" ";
	cout<<endl;
}