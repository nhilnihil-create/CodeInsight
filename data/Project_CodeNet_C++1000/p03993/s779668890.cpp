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

const ll inf = 1e18+7;
const ll mod = 1e9+7;

//階乗
int factorial(int k){
    int result=1;
    for (int i=1;i<=k;++i){
        result*=i;
    }
    return result;
}

int main() {
    int n;
    cin>>n;

    vector<int>a(n);
    rep(i,n)cin>>a[i];

    int cnt=0;

    rep(i,n) if(a[a[i]-1]==i+1)cnt++;

    cout<<cnt/2<<endl;

}
