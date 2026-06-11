//-----------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
 
#define cinsc ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOR(i,k,n)  for(int64 i=k;i<(int)n;i++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define SQ(x) ((x)*(x))
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
//ONLINE_JUDGE   LOCAL
//-----------------------------------------------------------------------------

int64 powr(int64 x,int64 y,int64 p)  
{  
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % p;   
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 
 
void  in_o(){
#ifndef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cinsc;
}

//-----------------------------------------------------------------------------
 
 
 


int main(){
   // in_o();
    string s;
    cin>>s;
    int c = 0;
    FOR(i,0,s.size()-1){
        if(s[i]!=s[i+1])c++;
    }
    cout<<c<<endl;
    return 0;
}
