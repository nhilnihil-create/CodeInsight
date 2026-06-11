
// author-Shivam gupta

#include <bits/stdc++.h>


using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define IN(A, B, C) assert( B <= A && A <= C)

#define MP make_pair
#define FOR(i,a) for(int i=0;i<a;i++)

#define FOR1(i,j,a) for(int i=j;i<a;i++)

#define EB emplace_back

#define INF (int)1e9

#define EPS 1e-9

#define PI 3.1415926535897932384626433832795

#define MOD 1000000007

#define read(type) readInt<type>()
#define max1 1000008
#define out(x) cout<<x<<'\n'
#define out1(x) cout<<x<<" "
#define END cout<<'\n'
typedef long int li;

typedef unsigned long int uli;

typedef long long int ll;

typedef unsigned long long int  ull;


void fast(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
ll check(ll n,ll b){
  ll ans=0;
  while (n>0){
    ans+=n%b;
    n/=b;
  }
  return ans;
}
ull na(ull m, ull n)
{
    // We have to calculate m+n-2 C n-1 here
    // which will be (m+n-2)! / (n-1)! (m-1)!
    ull path = 1;
    for (ull i = n; i < (m + n - 1); i++) {
        path *= i;
        path /= (i - n + 1);
    }
    return path;
}

int main() {
int a,b,c;
cin>>a>>b>>c;
cout<<((a+b)*c)/2;


}


