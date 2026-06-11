#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
int cnt;
void construct(long long n,int &k)
{
	if(n==1)
	{
		ans.push_back(1);
		k=1;
		return;
	}
	if(n%2)
	{
		construct((n-1)/2,k);
		k++;
		ans.push_back(k);
	}
	else 
	{
		construct(n-1,k);
		k++;
		ans.insert(ans.begin(),k);
	}
}

int main()
{	
	long long n;
	cin>>n;
	construct(n,cnt);
	for(int i=1;i<=cnt;i++)
		ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}