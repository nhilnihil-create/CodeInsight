#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	int h,w;
	cin >> h >> w;
	vector<string> a(h);
	for(int i = 0;i<h;i++)cin >> a[i];
	vector<int> cnt(26);
	for(int i=0;i<h;++i)
	{
		for(int j = 0;j<w;++j)
		{
			cnt[a[i][j]-'a']++;
		}
	}
	
	for(int i =0;i<26;i++)cnt[i]%=4;
	//両方奇数奇数がひとつだけでおｋ
	if((h%2==1)&&(w%2==1))
	{
		ll is  = 0;
		ll c = 0;
		for(int i = 0;i<26;i++)
		{
			is+=cnt[i]&1;
			c += cnt[i]/2;
		}
		if(is>1||c>(h+w)/2)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
		
	}//片方偶数奇数が残ってたらアウト
	else if((h%2==1&&w%2==0)||(h%2==0&&w%2==1))
	{
		//cout<<';'<<endl;
		ll c = 0;
		for(int i = 0;i<26;i++)
		{
			c += cnt[i]/2;
			if(cnt[i]%2==1)
			{
				cout<<"No"<<endl;
				return 0;
			} 
		}
		ll gusu = h&1?w:h;
		//cout<<gusu<<endl;
		//cout<<c<<endl;
		if(c>gusu/2)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
		

	}
	else//両方偶数全部ゼロ
	{
		
		bool is = true;
		for(int i =0;i<26;i++)
		{
			if(cnt[i])
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
		cout<<"Yes"<<endl;


	}
	return 0;
}