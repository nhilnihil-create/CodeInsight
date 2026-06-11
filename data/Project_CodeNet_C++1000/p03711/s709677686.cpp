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
using namespace std;

typedef long long ll;


#define ceil(a,b)  ( !(a%b) ? a/b : a/b+1 )
#define all(a)  (a).begin(),(a).end()
#define allr(a) (a).rbegin(),(a).rend()
#define endl '\n' 
#define debug(a) cin>>#a>>a;
//vector<ll> primes{ }

int gcd( int a, int b ) { return !a ? b : gcd( b%a, a); }
int lcm( int a, int b ) { return (a*b)/gcd(a,b); } 

int main(){
    vector<int> a{ 1,3,5,7,8,10,12 };
    vector<int> b { 4,6,9,11 };
    int x,y;
    cin>>x>>y;
    if( (find(all(a),x) != a.end() && find(all(a),y) != a.end()) || ( find(all(b),x) != b.end() && find(all(b),y) != b.end()) ){
        cout<<"Yes";
    } else{
        cout<<"No";
    }
    cout<<endl;

}
