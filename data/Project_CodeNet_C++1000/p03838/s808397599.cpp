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
    int x,y;
    cin >> x >> y;
    int num = abs(abs(x)-abs(y));
    if((x<0&&y>0)||(x>0&&y<0)){
        cout << num+1 << endl;
        return 0;
    }
    else if(x==0){
        if(x<y)cout << num << endl;
        else cout << num+1 << endl;
    }
    else if(y==0){
        if(y>x)cout << num << endl;
        else cout << num+1 << endl;
    }
    else if(x<y){
        cout << num << endl;
        return 0;
    }
    else if(x>y){
        cout << num+2 << endl;
    }
    return 0;
}    
