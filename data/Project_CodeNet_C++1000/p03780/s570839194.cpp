#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
   int n,k;
   cin>>n>>k;
   vector<int> a;
   rep(i,n){
       int x;cin>>x;
       if(x<k)a.push_back(x);
   }
   int m=a.size();
   sort(a.begin(),a.end());
   bitset<5000> b[m][2];
   b[0][0]=1;
   b[m-1][1]=1;
   rep(i,m-1)b[i+1][0]=b[i][0]|(b[i][0]<<a[i]);
   rep(i,m-1)b[m-i-2][1]=b[m-i-1][1]|(b[m-i-1][1]<<a[m-i-1]);
   int ok=m,ng=-1;
   while(ok-ng>1){
       int mid=(ok+ng)/2;
        bool flag=false;
       REP(i,k-a[mid],k)rep(j,i+1){
           if(b[mid][0][j]&&b[mid][1][i-j]){
               flag=true;
               break;
           }
       }
       if(flag)ok=mid;
       else ng=mid;
   }
   cout<<ok<<endl;
   return 0;
}