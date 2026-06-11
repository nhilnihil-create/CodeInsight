#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1000000007; 
using plong = pair<long,long>;

ll max(ll a,ll b,ll c){
    return max(max(a,b),c);
}

ll min(ll a,ll b,ll c){
    return min(min(a,b),c);
}
ll H,W;
ll a=0,b=0,c=0;
ll _min = (ll)3e9;
void cmp(ll H,ll W){
    for(ll i=1;i<H;i++){
        a = W*i;
        if((H-i)%2==0){
            b = W*(H-i)/2;
            c = b;
        }else{
            a = W*i;
            b = W*((H-i)/2);
            c = W*((H-i)/2+1);
        }
        ll s_max = max(a,b,c);
        ll s_min = min(a,b,c);
        _min = min(_min,s_max-s_min);
    }
}

void cmp1(ll H,ll W){
    for(ll i=1;i<H;i++){
        a = W*i;
        if(W%2==0){
            b = W/2*(H-i);
            c = b;
        }else{
            b = W/2*(H-i);
            c = (W/2+1)*(H-i);
        }
        ll s_max = max(a,b,c);
        ll s_min = min(a,b,c);
        _min = min(_min,s_max-s_min);
    }
}

int main(){   
    cin>>H>>W;
    cmp(H,W);
    cmp(W,H);
    cmp1(H,W);
    cmp1(W,H);
    cout<<_min<<endl;
    
}