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
    int w,h,n;cin >>w>>h>>n;
    vector<int>x(w,0);
    vector<int>y(h,0);
    for (int i = 0; i < n; ++i) {
        int a,b,c;cin >>a>>b>>c;
        if(c==1){
            for (int j = 0; j <a; ++j) {
                x[j]++;
            }
        }
        if(c==2){
            for (int j = a; j <w;++j) {
                x[j]++;
            }
        }
        if(c==3){
            for (int j = 0; j <b ; ++j) {
                y[j]++;
            }
        }
        if(c==4){
            for (int j =b; j <h; ++j) {
                y[j]++;
            }
        }
    }
    int ans=0;
//    for (int i = 0; i < w; ++i) {
//        cout <<x[i]<<" ";
//    }
//    cout <<endl;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if(x[i]==0&&y[j]==0)ans++;
        }
    }
    cout <<ans <<endl;
}
