
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

int main() {
    ll n,k,x,y;
    cin>>n>>k>>x>>y;
    if(k>=n){out(n*x);}
    else{
        out(k*x+(n-k)*y);
    }
}



