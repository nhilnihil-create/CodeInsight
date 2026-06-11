#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<functional>
#include<queue>
#include<cmath>
#include<algorithm>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cout << '!' << endl;
#define REP(i,n) for(int i = 0;i < (n);i++)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cout << v[i] << ' ';cout << endl << endl;}
#define SHOW2d(v,i,j) {for(int a = 0;a < i;a++){for(int b = 0;b < j;b++)cout << v[a][b] << ' ';cout << endl;}cout << endl;}
#define ALL(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

int main()
{
	int h,w,k;
	
	cin >> h >> w >> k;
	
	REP(i,h)
	{
		REP(j,w)
		{
			int n = 0;
			if((i+j) % (2*k) > (k-1))
			{
				n++;
			}
			if((i*((2*k)-1)+j) % (2*k) > (k-1))
			{
				n += 2;
			}
			
			cout << "RYGB"[n] ;
		}

		cout << endl;
	}
		
	return 0;
}