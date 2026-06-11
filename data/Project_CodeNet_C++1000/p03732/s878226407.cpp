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

    ll n,w; cin>>n>>w;
    map<ll, vector<ll>> mp;

    vector<ll> weights;
    ll weight, value;
    loop(i,n){
        cin>>weight>>value;
        mp[weight].push_back(value);
        weights.push_back(weight);
    }

    sort(weights.begin(), weights.end());
    weights.erase(unique(weights.begin(), weights.end()), weights.end());
    while(weights.size() < 4) weights.push_back(0);


    for(auto it= mp.begin(); it!= mp.end(); it++){
        vector<ll> &v = it->second;
        sort(v.begin(), v.end());

        reverse(v.begin(), v.end());
    }

    for(auto it= mp.begin(); it!= mp.end(); it++){
        vector<ll> &v = it->second;
        loop1(i, v.size()-1)
            v[i]+= v[i-1];
    }

    ll ans=0;

    for(ll a= 0; a <= mp[weights[0]].size(); a++){
        for(ll b=0; b <= mp[weights[1]].size(); b++){
            for(ll c=0; c <= mp[weights[2]].size(); c++){
                for(ll d=0; d <= mp[weights[3]].size(); d++){
                    if((a*weights[0])+(b*weights[1])+(c*weights[2])+(d*weights[3]) > w) continue;

                    ll sum=0;
                    if(a!=0) sum += mp[weights[0]][a-1];
                    if(b!=0) sum += mp[weights[1]][b-1];
                    if(c!=0) sum += mp[weights[2]][c-1];
                    if(d!=0) sum += mp[weights[3]][d-1];

                    ans= max(ans, sum);
                }
            }
        }

    }

    cout<<ans;




}
