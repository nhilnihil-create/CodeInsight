#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
#define pb(n,m) n.push_back(m)
#define pii pair<int,int>
using namespace std;
//using bint=boost::multiprecision::cpp_int;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  int n,m=0,c=0; cin>>n;
  vector<int> col(8);
  rep(i,0,n){
    int a;
    cin>>a;
    if(a<3200) col[a/400]++;
    else m++;
  }
  rep(i,0,8) if(col[i]>0) c++;
  if(c>0) co(c<<" "<<c+m);
  else if(m>0) co(1<<" "<<m);
  
  return 0;
}