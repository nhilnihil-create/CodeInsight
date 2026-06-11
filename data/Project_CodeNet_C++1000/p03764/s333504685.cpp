#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
//#define mp make_pair

ll ans, ya[101010],xa[101010], ay,ax, n, m, x[101010], y[101010];


int main(){

ios::sync_with_stdio(0);
cin.tie(0);

cin >> n >> m;
rep(i,1,n)cin >> x[i];
rep(i,1,m)cin >> y[i];

sort(x+1, x+n+1);
sort(y+1, y+m+1);


rep(i, 1, m-1){
ya[i]= abs(y[i+1]-y[i]);

}

rep(i, 1, n-1){
xa[i]= abs(x[i+1]-x[i]);
}

for(ll i =1; i<=m-1; i++){
ay += (((ya[i]*(m-i))%mod)*(i))%mod;
}

for(ll i =1; i<=n-1; i++){
ax += (((xa[i]*(n-i))%mod)*(i))%mod;
}
ax = ax%mod;
ay = ay%mod;
ans = ay*ax%mod;
cout << ans << endl;

}

/*

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
//#define mp make_pair

ll ans, ya[101010],xa[101010], ay, n, m, x[101010], y[101010];


int main(){

ios::sync_with_stdio(0);
cin.tie(0);

cin >> n >> m;
rep(i,0,n-1)cin >> x[i];
rep(i,0,m-1 )cin >> y[i];

sort(x, x+n);
sort(y, y+m);

rep(i, 0, m-2){
ya[i]= abs(y[i+1]-y[i]);
xa[i]= abs(x[i+1]-x[i]);
}

for(ll i= m-2;i >=0; i++){
ay += (ya[m-i-2]*(i+1))*(m-1-i);
}
cout << ay%mod << endl;

ans = (ay*(x[1]-x[0]))%mod;
rep(i, 1, n-2){
ans+= ((ay*(x[i+1]-x[0])%mod) + (ay*(x[i+1]-x[i])%mod))%mod;
//cout << ans << endl;
}

cout << ans%mod << endl;

}
*/
