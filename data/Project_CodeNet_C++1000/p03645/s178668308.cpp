#include<bits/stdc++.h>
using namespace std;
//using p=pair<int,int>;
typedef long long ll;
//#define rep(i,N) for(int i=0;i<N;i++)
 int main ( ) {

    int n , m;
    cin >> n >> m;
    vector<bool> vis(n+1,false) ;
    bool ans = false ;

  for ( int i = 0 ; i < m; i++)
  {
  int a , b ;
  cin >> a >> b ;

  if( 1 <= a && a < b && b <= n ) {
    if ( a == 1 ){
        if(vis[b] ) ans = true ;

      vis[ b ] = true ;
    }
    else if ( b == n ){

      if (vis[a]) ans = true ;

      vis[a] = true ; }

  }

  }




if (!ans)
cout<<"IMPOSSIBLE" ;
else
cout<< "POSSIBLE" <<endl ;

return 0;
}

