#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;


int main(){
    int n;cin >>n;
    int ans;int now=-1;
    for (int i = 1; i <=n; ++i) {
        int c=i;
        int cnt=0;
        while(c%2==0){
            cnt++;
            c/=2;
        }
        if(now<cnt){
            ans=i;
            now=cnt;
        }
    }
    cout <<ans <<endl;
    return 0;
}