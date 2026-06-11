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
    vector<int>ans;
    vector<int>rans;
    for (int i = 0; i < n; ++i) {
        int c;cin >>c;
        if(i%2==0){
            ans.push_back(c);
        }
        else {
            rans.push_back(c);
        }
    }
    if(n%2==1){
        reverse(all(ans));
        for (int i = 0; i < ans.size(); ++i) {
            cout <<ans[i]<<endl;
        }
        for (int i = 0; i < rans.size(); ++i) {
            cout <<rans[i]<<endl;
        }
    }
    else {
        swap(ans,rans);
        reverse(all(ans));
        for (int i = 0; i < ans.size(); ++i) {
            cout <<ans[i]<<endl;
        }
        for (int i = 0; i < rans.size(); ++i) {
            cout <<rans[i]<<endl;
        }
    }
    return 0;
}
