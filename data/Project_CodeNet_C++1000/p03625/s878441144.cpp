#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n;
    cin>>n;
    vector<int> dat(n+1);
    rep(i,n){
        cin>>dat[i];
    }
    sort(dat.begin(),dat.end());
    reverse(dat.begin(),dat.end());
    ll first=0,second=0;
    rep(i,n){
        if(dat[i]==dat[i+1]){
            if(first==0){
                first=dat[i];
                i++;
            }
            else{
                second=dat[i];
                break;
            }
        }
    }
    cout<<first*second<<endl;
    return 0;
}