#include<bits/stdc++.h>
#define inf 0x7fffffff
#define RG register
#define maxn 100005
#define maxm 205
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}
    return x * f;
}

int n, m, a[55], A, sum;
ll f[55][55][2505], ans;
int main(){
	int i, j, k;
	n = read(), A = read();
	for(i = 1;i <= n;i++) a[i] = read(), sum += a[i];
	f[0][0][0] = 1;
	for(i = 1;i <= n;i++){
		for(j = 0;j <= i;j++){
			for(k = 0; k <= sum;k++){
				if(i > j) f[i][j][k] = f[i - 1][j][k];
				if(k >= a[i] && j) f[i][j][k] += f[i - 1][j - 1][k - a[i]];
			}
		}
	}
	for(i = 1;i <= n;i++) ans += f[n][i][i * A];
	cout<<ans; 
	return 0;
}
