#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define inf 1000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
//#define mp make_pair

ll n, a[101010], as[101010], ans=0, mx,t;

int main(){

cin >> n >> t;
rep(i, 1, n){
cin >> a[i];
}
rep1(i,n, 1 ){
as[i]=max(as[i+1], a[i]);
}

rep(i, 1, n){
ll temp = as[i+1]-a[i];

mx = max(mx, temp);

}

rep(i, 1, n){
if(as[i]-a[i]==mx)ans++;
}

cout << ans << endl;


return 0;}
