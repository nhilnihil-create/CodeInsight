#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	cin >> h >> w;
	vector<vector<string>> s(h,vector<string>(w,""));
	int tt=-1,yk=-1;
	for(int i = 0;i < h;i++)
	{
		for(int j = 0;j < w;j++)
		{
			cin >> s.at(i).at(j);
			if(s.at(i).at(j) == "snuke")
			{
				tt = i;
				yk = j;
				break;
			}
			if(tt >= 0)
			{
				break;
			}
		}
	}
	tt++;
	char ykk = 'A' + yk;
	cout << ykk << tt <<endl;
	return 0;
}
