#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int n;
    cin>>n;

    //mapのソートは宣言時に
    map<ll,ll,greater<ll>> A;
    rep(i,n){
        ll a;
        cin>>a;
        A[a]++;
    }

    vector<ll> tateyoko;
    //0で初期化されているのでpush_backはダメか？
    for(auto p:A){
        if(p.second>=4){
            tateyoko.push_back(p.first);
            tateyoko.push_back(p.first);
        }
        if(p.second>=2) tateyoko.push_back(p.first);
    }

    if(tateyoko.size()>=2)cout<<tateyoko[0]*tateyoko[1]<<endl;
    else cout<<0<<endl;

}

//pushbackの使い方(0に上書き不可)