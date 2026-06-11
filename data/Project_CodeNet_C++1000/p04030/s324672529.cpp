#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define SI(a) scanf("%d",&a)
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long ll;
const int mod = 998244353;
const int maxn = 110;
using namespace std;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
ll quick_pow(ll x,ll n,ll mod){
	ll res = 1;
	while(n > 0){
		if(n & 1)	res = res * x % mod;
		x = x * x % mod;
		n >>= 1;//相当于n=n/2.详情请参考位移运算符。
	}
	return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string str;
    char ans[10];
    cin>>str;
    int len = str.length();
    int pos1 = 0,pos2 = 0;
    while(pos1!=len)
    {
        if(str[pos1]=='B'&&pos2==0){pos1++;continue;}
        else if(str[pos1]=='B'&&pos2!=0){pos2--;pos1++;continue;}
        else{
            ans[pos2] = str[pos1];
            pos1++;pos2++;
        }
    }
    ans[pos2]='\0';
    cout<<ans<<endl;
    return 0;
}
