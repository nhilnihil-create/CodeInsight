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
    int x,y;cin >>x>>y;
    vector<int>a={4,6,9,11};
    char ansx='c',ansy='c';
    for (auto e:a){
//        cout <<e<<endl;
        if(x==e) {
            ansx='a';
        }
        if(y==e){
            ansy='a';
        }
    }
    if(x==2)ansx='b';
    if(y==2)ansy='b';
    if(ansx==ansy)puts("Yes");
    else puts("No");
    return 0;
}