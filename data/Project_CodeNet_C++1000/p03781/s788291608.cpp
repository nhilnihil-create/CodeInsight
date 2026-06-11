#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define P pair<int,int>
#define vp vector<P>
#define PP pair<int,P>
#define vpp vector<PP>
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(x) (x).begin(),(x).end()
int main(){
    int x;
    cin>>x;
    int sum=0;
    int n=0;
    while(sum<x){
        n++;
        sum+=n;
    }
    cout<<n<<endl;
    return 0;
}