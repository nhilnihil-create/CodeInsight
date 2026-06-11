#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

ll com[51][51];

int main(){
    int n,a,b; cin >> n >> a >> b;

    com[0][0]=1;
    for (int i=1;i < 51;i++){
        for (int j=0;j <= i;j++){
            com[i][j]+=com[i-1][j];
            if (j > 0) com[i][j]+=com[i-1][j-1];
        }
    }
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end(),greater<ll>());

    ll sum=0;
    for (int i=0;i < a;i++) sum+=v[i];
    double ave = double(sum)/a;

    ll res=0;
    int num=0;
    for (int i=0;i <n;i++) if (v[i]==v[a-1]) num++;
    if (v[0] == v[a-1]){
        for (int j=a;j <= b;j++) res+=com[num][j];
    }
    else {
        int ta=0;
        for (int h=0;h < a;h++) if (v[h]==v[a-1]) ta++;
        res+=com[num][ta];
    }
    printf("%.8f\n",ave);
    cout << res << endl;
    return 0;
}