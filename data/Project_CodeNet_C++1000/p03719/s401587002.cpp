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
#define x first
#define y second
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
int l,n;
vector<int> cuts;
ll dp[1100][1100];

ll solve(int i, int j){
    ll &ret= dp[i][j];
    if(ret != -1)
        return ret;

    int cur= lower_bound(cuts.begin(), cuts.end(), i+1) - cuts.begin();
    if(cur == cuts.size() || cuts[cur] >= j)
        return ret= 0;



    ret= 10000000;
    while(cur < n && cuts[cur] < j){
        ret = min(ret, solve(i, cuts[cur]) + solve(cuts[cur], j) + j - i);
        cur++;
    }

    return ret;
}
int main() {
    //freopen("input.txt" , "r" , stdin) ;
    //freopen("output.txt" , "w" , stdout) ;

    cin.tie(0);
    cin.sync_with_stdio(0);


    int a,b,c; cin>>a>>b>>c;
    if(c >= a && c <= b)
        cout<<"Yes";
    else
        cout<<"No";

}
