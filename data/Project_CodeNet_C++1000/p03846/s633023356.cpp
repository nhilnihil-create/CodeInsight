/*I wanna be the very best, like no one ever was...*/

#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and Constants    *******/

#define ll long long
#define ull unsigned long long 
#define ld long double
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, j, k) for (int i = j ; i < k ; ++i)
#define rrep(i, j, k) for (int i = j; i > k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(i, a) for(auto i: a)
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define debug(a) cout << #a << ": " << a << endl
#define Flag(n) cout << "here " << n << endl
#define mp make_pair
#define pb push_back

#define endl '\n';
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll POSITIVE_INFINITY = 9223372036854775807;
const ll NEGATIVE_INFINITY = -9223372036854775807;
const ll MOD = 1000000007;
const ld PI = acos(-1.0);
 

#define TRACE
#ifdef TRACE
#define see(...) __f(#__VA_ARGS__,__VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr<<name<<" : "<<arg1<<endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma=strchr(names+1,',');cerr.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1, args...);
}
#else
#endif


int pow(int a , int n ){
    ll res =1;
    while(n){
        if(n%2==1){
            res= (res*a)%MOD;
        }
        a=(a*a)%MOD;
        n/=2;
    }
    return res;
}



int main() {
    io;
    // freopen("in","r",stdin); 
    // freopen("out","w",stdout);
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i,0,n)cin>>v[i];
    ll flag = 1;
    sort(all(v));
   for(long i=n-1; i>1; i-=2){
        if(i!=0){
            if(v[i]!=i || v[i-1]!=i){
                flag=false;
            }
        }else{
            if(v[0]!=0){
                flag=false;
            }
        }
    }
     if(!flag){
        cout << 0 <<endl;
    }else{
        long result=1;
        for(long i=0; i<n/2; i++){
            result=result*2;
            result=result%(1000000000+7);
        }
        std::cout << result << endl;    }

 
 
 
    
 
    return 0;
}