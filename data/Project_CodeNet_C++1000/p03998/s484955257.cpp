#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
typedef long long ll;
//
int main(){
   string a,b,c;
   cin>>a>>b>>c;
   int x=1,y=0,z=0;
   char check=a[0];
   bool flag=true;
   char ans='f';
   while(flag){
   switch(check){
      case 'a':check=a[x];
      if(x==a.size()) {ans='A';flag=false;break;}
      x++;
      break;
      case 'b':check=b[y];
      if(y==b.size()) {ans='B';flag=false;break;}
      y++;
      break;
      case 'c':check=c[z];      
      if(z==c.size()) {ans='C';flag=false;break;}
      z++;
      break;
   }
   }
   cout<<ans<<endl;
}
