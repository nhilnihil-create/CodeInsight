#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    int n,c1=0,c2=0;
    cin >> n;
    bool flag = false;
    REP(i,n){
        int a;
        cin >> a;
        if(a%4==0)c1++;
        else if(a%2==0)flag = true;
        else c2++;
    }
    if(flag){
        if(c1>=c2)cout<<"Yes"<<endl;
        else cout << "No" << endl;
    }
    else {
        if(c1>=c2-1)cout<<"Yes"<<endl;
        else cout << "No" << endl;
    }
    return 0;
}    
