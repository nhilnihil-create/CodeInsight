#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define ll long long
#define loop(i,n) for(int i=0; i<n; i++)
#define loop1(i,n) for(int i=1; i<=n; i++)
#define loopi(i,s,e) for(int i=s; i < e; i++)
#define loopiRev(i,s,e) for(int i=s; i >= e; i--)
#define PI 3.14159265359
//#define x first
//#define y second
#define point pair<double,double>
#define len(s)   (int)s.length()
#define sz(v)    (int)v.size()
#define all(a)   a.begin(),a.end()
#define clr(x, val)	memset((x), (val), sizeof(x))

void initialize(vector<int> &F, int n){
    F = vector<int> (n+1, 0);

    for(int i=2; i*i  <= n; i++){
        if(F[i] == 0)
            for(int k=i*i; k <=n ; k+= i)
                if(F[k] == 0) F[k] = i;
    }
}
//you don't know math, unless you can do math!
int OO = 1e7;

int main() {

    //freopen("input.txt" , "r" , stdin) ;
    //freopen("output.txt" , "w" , stdout) ;

    //cin.tie(0);
    //cin.sync_with_stdio(0);

    int a,b,c; cin>>a>>b>>c;
    if(b - a == c - b)
        cout<<"YES";
    else
        cout<<"NO";

}
