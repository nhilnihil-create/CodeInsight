#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>

using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e9+7;
const ll mod = 1e9+7;

int main() {
    int n,cnt=0;
    cin>>n;

    vector<int>x(100001);
    rep(i,n){
        int l,r;
        cin>>l>>r;

        rep2(i,l,r)x[i]++;
    }

    rep2(i,1,100000)cnt+=x[i];

    cout<<cnt<<endl;

}



