#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;


bool red[100500];
int num[100500];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m; cin >> n >> m;
  
  memset(red,false,sizeof(red));
  rep(i,100500) num[i] = 1;
  red[0] = true;
  rep(i,m){
    int x , y; cin >> x >> y; x--; y--;
    num[x]--; num[y]++;
  	if(red[x]) red[y] = true;  
    if(num[x] == 0) red[x] = false;
  }
  
  int ans = 0;
  rep(i,n) if(red[i]) ans++;  
  cout << ans << endl;
  
  
  return 0;
}