#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

int main(){
    ll X,A,B;
    cin>>X>>A>>B;
    if(X<(B-A))cout<<"dangerous";
    else if(0<(B-A)&&(B-A)<=X)cout<<"safe";
    else cout<<"delicious";
    return 0;
}