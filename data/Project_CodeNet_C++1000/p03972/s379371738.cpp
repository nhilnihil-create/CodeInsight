#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

int main(){
    ll W, H;
    cin >> W >> H;
    vector<pair<int,int>> cost;
    for(int i=0; i<W; i++){
        int p;  cin >> p;
        cost.push_back({p,0});
    }
    for(int i=0; i<H; i++){
        int p;  cin >> p;
        cost.push_back({p,1});
    }

    sort(cost.begin(), cost.end());
    W++;  H++;
    ll ans = 0;
    for(auto p:cost){
        if(p.second==0){
            ans += p.first*H;
            W--;
        }else if(p.second==1){
            ans += p.first*W;
            H--;
        }
    }
    cout << ans << endl;
}
