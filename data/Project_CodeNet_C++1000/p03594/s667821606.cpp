#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <deque>
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


const ll MOD=998244353;
const int N=510000;

main(){
    int h=in(),w=in();
    int d=in();
    if(d%2){
        rep(i,h){
            rep(j,w){
                cout<<((i+j)&1 ? 'R' : 'B');
            }
            cout<<endl;
        }
    }
    else{
        vector<char> c={'R','G','Y','B'};
        rep(i,h){
            rep(j,w){
                if((i+j)&1){
                    int x=i+j,y=i-j;
                    int t=(((x-1)/2%d+d)%d < d/2 ? 2 : 0) + (((y-1)/2 %d +d)%d <d/2 ? 1:0);
                    cout<<c[t];
                }
                else{
                    int x=i+j,y=i-j;
                    int t=((x/2%d+d) % d < d/2 ? 2 : 0) + ( ( y/2 % d + d) % d < d/2 ? 1 : 0 );
                    cout<<c[t];
                }
            }
            cout<<endl;
        }
    }
}