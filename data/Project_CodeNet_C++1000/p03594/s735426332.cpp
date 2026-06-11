#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,n) for(ll i=0;i<(n);i++)  
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp make_pair
#define pb push_back  
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second  
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-5;
const double PI = M_PI;  
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define SHOWARRAY(ar,i,j) REP(a,i)REP(b,j)cerr<<ar[a][b]<<((b==j-1)?((a==i-1)?("\n\n"):("\n")):(" "))

#define mt make_tuple

string s = "RGBY";
int main(){
  int h,w,d; cin >> h >> w >> d;
  
  int x = 0;
  rep(i,h){
    rep(j,w)
      cout <<s[(i+j)/d % 2 + 2*((i-j+1000*d)/d%2)];
    cout << endl;
  }
}