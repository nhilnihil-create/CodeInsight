#include<bits/stdc++.h>
using namespace std;
int tp;
vector<int> vl,vr;
void work(long long n)
{
	if (n==1) return;
	work(n/2);
	tp++;vl.push_back(tp);vr.push_back(tp);
	if (n&1) {tp++;vl.push_back(tp);vr.insert(vr.begin(),tp);}
}
int main()
{
	long long n;scanf("%lld",&n);
	work(n+1);
	printf("%d\n",vl.size()+vr.size());
	for (int i=0;i<vl.size();i++) printf("%d ",vl[i]);
	for (int i=0;i<vr.size();i++) printf("%d ",vr[i]);
}