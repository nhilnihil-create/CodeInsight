#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;


int main() {
    ios_base::sync_with_stdio(false);

    vector<int> x(13);
    x[4]=1;
    x[6]=1;
    x[9]=1;
    x[11]=1;
    x[2]=2;

    int a,b; 
    cin >> a >> b;
    if (x[a]==x[b]) cout << "Yes" << endl;
    else cout << "No" << endl;
    

    return 0;   
}
