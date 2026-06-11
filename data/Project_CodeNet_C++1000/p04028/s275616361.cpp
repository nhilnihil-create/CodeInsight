	#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<stack>
#include<queue>
#include <iomanip>
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
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

ll dp[5050][5050];
ll wari[5050];

class Mod
{
//    static const int MOD = 1000000007;
    long long a;
public:
    Mod(){
        a = 0;
    }
    Mod(long long x){
        a = (x % MOD + MOD) % MOD;
    }
    const Mod operator+(const Mod& x) const{
        return Mod(a + x.a);
    }
    const Mod operator-(const Mod& x) const{
        return Mod(a - x.a);
    }
    const Mod operator*(const Mod& x) const{
        return Mod(a * x.a);
    }
    const Mod operator/(const Mod& x) const{ //フェルマーの小定理、aとMODが互いに素の時のみ
        if(x.a == 0)return 0;
		if(a % x.a == 0)return Mod(a/x.a);
		int b = MOD - 2;
        long long c = x.a;
        long long ret = 1;
        while(b > 0){
            if(b & 1){
                ret *= c;
                ret %= MOD;
            }
            c *= c;
            c %= MOD;
            b >>= 1;
        }
        return Mod(a * ret);
    }
    long long getValue(){
        return a;
    }
};


int main()
{
	int n;cin >> n;
	string str;cin >> str;
	wari[0] = 1;
	for(int i = 1;i < 5010;i++)wari[i] = (wari[i-1]*2)%MOD;
	
	dp[0][0] = 1;
	
	REP(i,n)
	{
		REP(j,5010)
		{
			if(j == 0)
			{
				if(j == 0)dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
			}
			else
			{
				dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
			}
			dp[i+1][j+1] = (dp[i+1][j+1] + 2*dp[i][j]) % MOD;
		}
	}
	
	//SHOW2d(dp,n+1,n+1);
	Mod ans(dp[n][str.size()]);
	ans = ans / wari[str.size()];
	
	cout << ans.getValue() << endl;
	
	
	return 0;
}