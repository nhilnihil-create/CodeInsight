#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<functional>
#include<queue>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cerr << v[i] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

int dx[] = {0,1,1,1,0,-1,-1,-1,0};
int dy[] = {0,1,0,-1,-1,-1,0,1,1};


int main()
{
	ll h,w,n;
	cin >> h >> w >> n;
	
	vector<set<pair<int,int> > > v(10);
	vector<pair<int,int> > node;
	map<pair<int,int>,int> mp;
	
	
	REP(i,n)
	{
		int x,y;
		cin >> x >> y;
		mp[MP(x,y)] = 1;
		node.PB(MP(x,y));
	}
    
	ll ze = 0;
	
	REP(i,n)
	{
		REP(j,9)
		{
			int cou = 0;
			int cx = node[i].FI + dx[j];
			int cy = node[i].SE + dy[j];
			if(cx < 2 || cx > h-1 || cy < 2 || cy > w-1)continue;
			REP(k,9)
			{
				if(mp.find(MP(cx+dx[k],cy+dy[k])) != mp.end())
				{
					cou++;
				}
			}
			v[cou].insert(MP(cx,cy));
		}		
	}
	
	REP(i,9)
	{
		ze += v[i+1].size();
	}
	
	cout << (h-2)*(w-2) - ze << endl;
	REP(i,9)
	{
		cout << v[i+1].size() << endl;
	}
	
	
	return 0;
}