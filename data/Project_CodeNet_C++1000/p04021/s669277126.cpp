#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> even;
	vector<int> odd;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(i%2==0)
			even.push_back(a[i]);
		else
			odd.push_back(a[i]);
	}
	sort(a.begin(),a.end());
	sort(even.begin(),even.end());
	sort(odd.begin(),odd.end());
	int cnt=0;
	int see=0;
	set<int> st;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			st.insert(a[i]);
	}
	for(int i=0;i<even.size();i++)
		st.insert(even[i]);
	
	cout << st.size()-even.size() << endl;

}