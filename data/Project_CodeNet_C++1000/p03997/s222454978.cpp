#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<cinttypes>
#include<stack>
#include<ctgmath>
using namespace std;

typedef long long ll;


#define ceil(a,b)  ( !(a%b) ? a/b : a/b+1 )
#define all(a)  (a).begin(),(a).end()
#define allr(a) (a).rbegin(),(a).rend()
#define endl '\n' 
#define debug(a) cin>>#a>>a;
//vector<ll> primes{ }
template<typename T>
T gcd( T a, T b ) { 
    return !a ? b : gcd( b%a, a); 
}

template<typename T>
T lcm( T a, T b ){
    return (a*b)/gcd(a,b); 
} 

int main(){
    int a = 0,b = 0, h = 0;
    cin >> a >> b >> h;
    cout << ((a+b)*h)/2 << '\n';
    return 0;
}
