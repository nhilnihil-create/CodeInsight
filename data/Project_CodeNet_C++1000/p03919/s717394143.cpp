#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define P pair<int,int>
#define vp vector<P>
#define PP pair<P,int>
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
    int a,b;
    cin>>a>>b;
    REP(i,a){
        REP(j,b){
            string t;
            cin>>t;
            if(t=="snuke"){
                cout<<(char)('A'+j)<<i+1<<endl;
            }
        }
    }
    return 0;
}