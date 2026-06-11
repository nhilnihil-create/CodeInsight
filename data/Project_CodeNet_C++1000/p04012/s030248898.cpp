#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define SI(a) scanf("%d",&a)
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 1e8;
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
string str;
int vis[30];
int main(){
    cin>>str;
    int len = str.length();
//cout<<len<<endl;
    if(len%2 == 1)cout<<"No"<<endl;
    else{
        ms(vis,0);
        for(int i = 0;i < len;i++)
        {
            vis[str[i]-'a']++;
            //cout<<str[i]-'a'<<endl;
        }
        bool flag = true;
        for(int i = 0;i < 26;i++)
              if(vis[i]%2!=0){
            cout<<"No"<<endl;flag = false;break;
        }
        if(flag)cout<<"Yes"<<endl;
    }
    return 0;
}
