#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define pll pair<ll, ll>
#define pi pair<int,int>

map<pll,int> black;

struct mat
{
	int r, c;
	bool operator<(const mat& b) const
	{
		return (pi(this->r,this->c) < pi(b.r,b.c));
	}
	bool operator=(const mat& b) const
	{
		return (pi(this->r,this->c) == pi(b.r,b.c));
	}
};

int dx[3] = {0,-1,-2}, dy[3] = {0,-1,-2};

map<mat,int> found;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	ll R[n], C[n];
	for(int i = 0; i < n; i++)
	{
		cin >> R[i] >> C[i];
		black[pll(R[i],C[i])] = 1;
	}
	ll ans[10];
	memset(&ans,0,sizeof(ans));
	ll tt = 0;
		int total = 0;
		for(int i = 0; i < n; i++)
		{
			//cout << "original: " << R[i] << " " << C[i] << endl;
			for(int px = 0; px < 3; px++)
			{
				if(R[i]+dx[px] > h-2 || R[i]+dx[px] <= 0) continue;
				int cnt = 0;
				int st = 0;
				for(int py = 0; py < 3; py++)
				{
					//cout << "new: " << R[i]+dx[px] << " " << C[i]+dy[py] << endl;
					if(C[i]+dy[py] > w-2 || C[i] + dy[py] <= 0) continue;
					mat rect;
					rect.r = R[i]+dx[px], rect.c = C[i]+dy[py];
					if(found.count(rect))
					{
						continue;
					}
					if(st == 0)
					{
						cnt = 0;
						for(int r = 0; r < 3; r++)
						{
							for(int c = 0; c < 3; c++)
							{
								int blck_cnt = black.count(pll((R[i]+dx[px])+r,(C[i]+dy[py])+c));
								//cout << blck_cnt << " ";
								if(blck_cnt)
								{
									cnt ++;
								}
							}
						//	cout << endl;
						}
					}
					else
					{
					/*	for(int r = 0; r < 3; r++)
						{
							for(int c = 0; c < 3; c++)
							{
								int blck_cnt = black.count(pll((R[i]+dx[px])+r,(C[i]+dy[py])+c));
								cout << blck_cnt << " ";
							}
							cout << endl;
						}*/
						for(int r = 0; r < 3; r++)
						{
							int blck_cnt = black.count(pll((R[i]+dx[px])+r,(C[i]+dy[py-1]+2)));
							int blck_cnt2 = black.count(pll((R[i]+dx[px])+r,(C[i]+dy[py])));
							cnt -= blck_cnt;
							cnt += blck_cnt2;
						}
					}
						found[rect]=cnt;
						ans[cnt]++;
						tt++;
					//cout << endl;
					st++;
				}
			}
		}
	ans[0] = ((h-2)*(w-2))-tt;
	for(int j = 0; j <= 9; j++)
	{
		cout << ans[j] << endl;
	}
	return 0;
}
