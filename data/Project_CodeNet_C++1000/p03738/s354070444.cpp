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

    string a,b; 
    cin >> a >> b;
    int flag=0;
    if (a.size()>b.size()) flag=1;
    else if (a.size()<b.size()) flag=-1;
    else {
        rep(i,a.size()) {
            if (a[i]>b[i]) {
                flag=1;
                break;
            } else if (a[i]<b[i]) {
                flag=-1;
                break;
            }
        }
    }
    if (flag==1) cout << "GREATER" << endl;
    else if (flag==-1) cout << "LESS" << endl;
    else cout << "EQUAL" << endl;
    

    return 0;   
}
