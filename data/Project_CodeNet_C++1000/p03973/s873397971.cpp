#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef long long int ll;
int main(void){
int n;
cin>>n;
queue<ll> a;
ll b;
for(int i=0;i<n;i++){
	cin>>b;
	a.push(b-1);
}
ll m=1,ans=0;
ans+=a.front();
a.pop();
for(int i=0;i<n-1;i++){
int t=a.front();
a.pop();
if(m==t){
	m++;
}else if(m<t){
ans+=t/(m+1);
}
}
cout<<ans<<endl;
	return 0;
}