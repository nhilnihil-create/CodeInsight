#include<bits/stdc++.h>
using namespace std;
#define int long long
int pw[22];
int s = -1e8;
signed main(){
	pw[0] = 1;
	string v;
	for(int i = 1 ; i <=10 ; ++i) pw[i] = pw[i - 1] * 10;
	for(int i = 10 ; i >= 0 ; --i)
	{
		int check = pw[i];
		cout << "? " << check << "\n";
		fflush(stdout);
		cin >> v;
		if(v == "Y") 
		{
			s = i;
			break;
		}
	}
	if(s == 10)
	{
		for(int i = 10 ; i >= 0 ; --i)
		{
			int check = pw[i] - 1;
			if(i == 0) check = 1;
			cout << "? " << check << "\n";
			fflush(stdout);
			cin >> v;
			if(v == "N") 
			{
				s = i;
				break;
			}
		}
	}
	int l = pw[s + 1] , r = pw[s + 2] - 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		cout << "? " << mid << "\n";
		fflush(stdout);
		cin >> v;
		if(v == "Y") r = mid;
		else l = mid + 1; 
	}
	if(l / 10 != 0) cout << "! " << l / 10;
	else cout << "! 1";
	fflush(stdout);
	
}