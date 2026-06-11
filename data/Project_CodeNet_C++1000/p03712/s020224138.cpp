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
    int a,b;
    cin>>a>>b;
    vector<vector<char>> v(a+2,vector<char>(b+2));
    for( int i=0; i<a+2; i++ ){
        for( int j=0; j<b+2; j++ ){
            if( i==0 || j==0 || i==a+1 || j == b+1){
                v[i][j] = '#';
            } 
        }
    }
    char c[a][b];
    for( int i=0; i<a; i++ ){
        for( int j=0; j<b; j++ ){
            cin>>c[i][j];
        }
    }
    for( int i=0; i<a+2; i++ ){
        for( int j=0; j<b+2; j++ ){
            if( i==0 || j==0 || i==a+1 || j == b+1){
                continue;
            }
            v[i][j] = c[i-1][j-1];
        }
    }
    for( int i=0; i<a+2; i++ ){
        for( int j=0; j<b+2; j++ ){
            cout<<v[i][j];
            if( j==b+1 )
                cout<<endl;
        }
    }
}
