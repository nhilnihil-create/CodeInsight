#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
ll MOD=1000000007;
int inf=1000000000;
ll INF=10000000000000000;
 
int main(){
    int n;
    cin >> n;
    int p=0,o=1;
    while (true){
        p+=o;
        if (p>=n) break;
        o++;
    }
    int u=p-n;
    rep(i,o){
        if (i+1==u) continue;
        cout << i+1 << endl;
    }
}