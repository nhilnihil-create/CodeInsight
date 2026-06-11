#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define endl "\n"

int main()
{
	faster;
	
	string n;
	map<char,int> cnt;
	cin >> n;
	for(int i = 0; i < n.size(); i++){
		cnt[n[i]]++;
	}
	
	bool flag = true;
	for(auto i: cnt) if(i.second % 2 != 0) flag = false;
	
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}