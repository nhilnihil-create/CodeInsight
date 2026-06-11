#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N=pow(10,9)+7; 

ll pow_mod(ll x){
    ll ans = 1;
    for(int i=0; i<x; i++){
        ans = (ans*2)%N;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> cnt(n,0);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        cnt.at(a)++;
    }
    bool possible=true;
    if(n%2==1){
        if(cnt.at(0)!=1) possible=false;
        for(int i=1; i<n; i++){
            if(i%2==0 && cnt.at(i)!=2) possible=false;
            if(i%2==1 && cnt.at(i)!=0) possible=false;
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(i%2==0 && cnt.at(i)!=0) possible=false;
            if(i%2==1 && cnt.at(i)!=2) possible=false;
        }
    }
    if(possible) cout << pow_mod(n/2) << endl;
    else cout << 0 << endl;
}