#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
#include <set>
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<int>> m(n,vector<int>(n));
    for(int i=0;i<n;i++){
        m[i][0]=a[i];
        for(int j=1;j<n;j++){
            m[i][j]=min(m[i][j-1],a[(i-j+n)%n]);
        }
    }
    ll ret=LLONG_MAX;
    for(int i=0;i<n;i++){
        ll cnt=0;
        for(int j=0;j<n;j++){
            cnt+=m[j][i];
        }
        cnt+=(ll)x*i;
        ret=min(ret,cnt);
    }
    cout<<ret<<endl;
}
