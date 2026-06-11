#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> findnge(vector<int> &ar)
{
	int n = ar.size();
	vector<int> res(n);
	stack<int> st;
	for(int i =0 ;i<n; i++)
	{
		while(st.size() && ar[st.top()] > ar[i])
		{
			res[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(st.size())
	{
		res[st.top()] = n;
		st.pop();
	}
	return res;
}
int32_t main(){
	int n ;
	cin >> n ;
	vector<int> ar(n);
	for(int i =0 ; i <n ;i++)
	{
		cin >> ar[i];
	}
	vector<int> nge = findnge(ar);
	vector<int> dp( n + 1);
	int sum =0;
	for(int i = n-1 ; ~i ; i--)
	{
		dp[i] = (nge[i] - i) * ar[i] + dp[nge[i]];
		sum += dp[i];
	}
	cout<< sum <<endl;

}