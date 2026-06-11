#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include <ctime>
#include<algorithm>
#include <initializer_list>
#include <cstring> 
#include <queue>
 
#define tii tuple<int,int>
#define vi vector<int>
#define vii vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>
 
#define mymod 1000000007
#define mx 99999999
#define mn -99999999
#define sz 101
 
using namespace std;
int n,k;
vi v;
int main() {
    clock_t tstart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Start
    cin>>n>>k;
    vi vec(10,1);
    int x;
    for(int i=0;i<k;i++) cin>>x, vec[x] = 0;
    
    v.clear();
    for(int i=0;i<10;i++) if(vec[i])v.push_back(i);
    k = v.size();
    int ans = 0;
    queue<int> q;
    q.push(0);
    while(n>ans) {
        ans = q.front();
        for(auto x:v) q.push(ans*10 + x);
        q.pop();
    }
    cout<<ans;
    // cout<<"\n\nTotal Time Taken : "<<(double)(-tstart + clock())/CLOCKS_PER_SEC<<"sec\n\n";
    return 0;
}
 
