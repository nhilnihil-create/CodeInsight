#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1061109567
#define int long long
#define pb push_back
#define in(s) freopen(s,"r",stdin);
#define out(s) freopen(s,"w",stdout);
#define fi first
#define se second
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
#define fa(i,x) for (auto i:x)
using namespace std;
int cnt=0,val=0;
int fpow(int a,int p) {
	int ans=1;
	fw (i,0,p) ans*=a;
	return ans;
}
int N=41289;
string N2=to_string(N);
char query(int x) {
	string temp=to_string(x);
	if (x<=N&&temp<=N2) return 'Y';
	if (x>N&&temp>N2) return 'Y';
	return 'N';
}
signed main() {
	//in("aome.inp");
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	/*
	How to get the number of digits N have?
	Keep asking queries of 1e9 down to 1. Let's say N have k digits. Then 1e(k + 1) will return N and
	1ek will return Y.
	k have been found. Now, binary search on this range simply.
	Query for mid:
	mid <= N. How to ask?
	We can see, mid * 10 > N with all possible mids. Also, it's the same as mid when comparing as
	strings. So the relations can be found.
	If we receive a Y, mid > N. Else, mid <= N
	*/
	int cur=9;
	//Problem: N = 1eK. Simply ask a query for N + 1. Should return Y.
	for (int i=1e9;i>=1;i/=10) {
		cout<<"? "<<i<<endl<<flush;
		char temp;
		//temp=query(i);
		cin>>temp;
		if (temp=='Y') {cnt=cur; break;}
		cur--;
	}
	//cout<<"cnt="<<cnt<<"\n";
	if (cnt==9) {
		for (int i=1;i<=1e9;i*=10) {
			cout<<"? "<<i+1<<endl<<flush;
			char temp;
			//temp=query(i+1);
			cin>>temp;
			if (temp=='Y') {
				cout<<"! "<<i<<endl<<flush;
				return 0;
			}
		}
	}
	//cout<<"passed?\n";
	int l=fpow(10,cnt),r=fpow(10,cnt+1)-1;
	while (l<r) {
		int mid=(l+r)>>1;
		cout<<"? "<<mid*10<<endl<<flush;
		char temp;
		//temp=query(mid*10);
		cin>>temp;
		if (temp=='Y') r=mid;
		else l=mid+1;
	}
	cout<<"! "<<l<<endl<<flush;
	return 0;
}