#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int MOD = 1000000007;

int main(){
    ll H,W;
    cin>>H>>W;
    ll N;
    cin>>N;
    vector<ll> a(N);
    for(ll i=0;i<N;i++){
        cin>>a[i];
    } 
    ll res[H][W];
    ll x=0,y=0;
    bool back=false;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<a[i];j++){
            res[x][y] = i+1;
            if((y==0&&back)||(y==W-1&&!back)){
                x++;
                back = !back;
            }else{
                if(back){
                    y--;
                }else{
                    y++;
                }
            }
        }
    }
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}