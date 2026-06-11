#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll=long long;
int main(){//WA
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll sum=0;
    for(int i=0;i<a;++i){
        sum+=v[i];
    }
    cout << setprecision(20) << fixed << sum/(double)a << endl;
    int num=0;
    for(int i=0;i<n && v[i]>=v[a-1];++i){
        if(v[i]==v[a-1])
            ++num;
    }
    int m;
    for(int i=0;i<n;++i){
        if(v[i]==v[a-1]){
            m=a-i;
            break;
        }
    }
    vector<vector<ll>> comb(n+1, vector<ll>(n+1, 0));
    for(int i=1;i<=n;++i){
        comb[i][0]=1, comb[i][i]=1;
        for(int j=1;j<i;++j){
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
        }
    }
    if(v[0]==v[a-1]){
        int e = min(b-a+m, num);
        ll ans=0;
        for(int i=m;i<=e;++i){
            ans+=comb[num][i];
        }
        cout << ans;
    }else{
        cout << comb[num][m];
    }

    return 0;
}