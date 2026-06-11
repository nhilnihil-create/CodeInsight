#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAX=100005;
const int MODUN=1e9+7;
long long int ans;
int n;
int a[MAX];
int main()
{
	ans=1;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	stack<int> s;
	for(int i=1;i<=n;++i){
		if(a[i]>=2*s.size()+1){
			s.push(i);
		}
		else{
			ans=(ans*(long long int)(s.size()+1))%MODUN;
		}
	}
	for(int i=1;i<=s.size();++i){
		ans=(ans*(long long int)(i))%MODUN;
	}
	cout<<ans<<endl;
	return 0;
}