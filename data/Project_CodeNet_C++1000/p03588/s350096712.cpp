#include<bits/stdc++.h>
#include<bitset>
#include<random>
#include<time.h>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 5e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code

int main()
{
  int n;
  cin>>n;
  int x, y;
  y= INT_MAX;
  rep(i, 0, n)
  {
    int a, b;
    cin>>a>>b;
    if(y > b)
      y = b, x = a;
  }
  cout<<(x + y)<<endl;
}
