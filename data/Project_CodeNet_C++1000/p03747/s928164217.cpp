#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int n,Len,T;
int x[N],w[N],res[N];
vector <int> v1,v2;
int s1,s2;
bool check(int x){
	int L,R;
	if (!w[0])
		L=(x-1)>>1,R=x>>1;
	else
		L=x>>1,R=(x-1)>>1;
	LL tot=1LL*(L/s1)*Len+v1[L%s1]
		  +1LL*(R/s2)*Len+v2[R%s2];
	return tot<=(T<<1);
}
int main(){
	n=read(),Len=read(),T=read();
	v1.clear();
	v2.clear();
	for (int i=0;i<n;i++){
		x[i]=read(),w[i]=read()&1;
		if (w[i])
			res[i]=(x[i]+T)%Len;
		else
			res[i]=((x[i]-T)%Len+Len)%Len;
		if (!w[i])
			v2.push_back(x[i]-x[0]);
		else
			v1.push_back((x[0]-x[i]+Len)%Len);
	}
	if (v1.empty()||v2.empty()){
		for (int i=0;i<n;i++)
			printf("%d\n",res[i]);
		return 0;
	}
	sort(res,res+n);
	sort(v1.begin(),v1.end());
	s1=v1.size(),s2=v2.size();
	int L=1,R=T<<1,ans=0;
	while (L<=R){
		int mid=(L+R)>>1;
		if (check(mid))
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
	int p0;
	if (ans==0)
		p0=w[0]?(x[0]+T)%Len:(x[0]+Len-T)%Len;
	else {
		if (!w[0])
			L=(ans-1)>>1,R=ans>>1;
		else
			L=ans>>1,R=(ans-1)>>1;
		int tot=L/s1*Len+v1[L%s1]+R/s2*Len+v2[R%s2];
		T=(T<<1)-tot;
		LL p=(R/s2*Len+v2[R%s2])-(L/s1*Len+v1[L%s1]);
		if (w[0]^(ans&1))
			p+=T;
		else
			p-=T;
		p/=2;
		p0=((p+x[0])%Len+Len)%Len;
	}
	int p=lower_bound(res,res+n,p0)-res;
	if (w[0]^(ans&1)){
		if (n>2&&res[(p+1)%n]==res[p])
			p=(p+1)%n;
	}
	else
		if (n>2&&res[(p+n-1)%n]==res[p])
			p=(p+n-1)%n;
	for (int i=0;i<n;i++)
		printf("%d\n",res[(p+i)%n]);
	return 0;
}