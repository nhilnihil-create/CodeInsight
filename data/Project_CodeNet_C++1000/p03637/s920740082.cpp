#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> ans(3,0);
    rep(i,n){
        ll a;
        cin >> a;
        if(a%4==0)++ans[0];
        else if(a%2==0)++ans[1];
        else ++ans[2];
    }
    bool a = true;
    if(n==1){
        if(ans[0]!=1)a = false;
    }else if(n==2){
        if(ans[2]>=2 || (ans[1]==1 &&ans[2]==1))a = false;
    }else if(n==3){
        if(ans[2]==2 && ans[1]==1)a = false;
        if(ans[1] == 2 && ans[2]==1)a = false;
        if(ans[2]>=3)a = false;
    }
    else{
        if(ans[1] != 0){
            ans[1] = 0;
            ans[2]++;
        }
        if(ans[0]+1<ans[2])a = false;
    }
    if(a)cout << "Yes"<<endl;
    else cout << "No" << endl;
    return 0;
}