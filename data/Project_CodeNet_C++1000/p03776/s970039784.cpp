#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll comb(ll a,ll b){
    static ll c[51][51] = {};

    if(c[a][b]>0) return c[a][b];
    else if(b==0) return 1;
    else if(a==b) return 1;
    else          return c[a][b] = comb(a-1,b-1)+comb(a-1,b);
}

int main(){
    int n,A,B,flag;
    cin >> n >> A >> B;
    vector<double> v(n);
    map<double,int> mp;
    double ave = 0;
    ll cnt = 0;
    bool single = true;
    for(int i = 0;i < n;i ++){
        cin >> v[i];
        mp[v[i]] ++;
    }
    sort(v.begin(),v.end(),greater<double>());
    for(int i = 0;i < A;i ++){
        ave += v[i];
        if(i && v[i]!=v[i-1]){
            single = false;
            flag = i;
        }
    }
    ave /= A;
    ll x = v[A-1],num = A-flag;
    if(single){
        for(int i = A;i <= min(B,mp[x]);i ++){
            cnt += comb(mp[x],i);
        }
    }else{
        cnt = comb(mp[x],num);
    }
    cout << setprecision(10) << ave << endl << cnt << endl;
}