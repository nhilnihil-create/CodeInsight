#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{   
    ll H , W ;
    cin >> H >> W ;
    ll N ;
    cin >> N ;

    ll a[N] ;
    for(ll i = 0 ; i < N ; i++){//ok
        cin >> a[i] ;
    }
     
    int now = 0 ;
    int count = 0 ;
    int map[H][W] ;
    for(int j = 0 ; j < H ; j++){
        for(int  k = 0 ; k < W ; k++){
           if(j % 2 == 0){
              map[j][k] = now + 1 ;
              //cout << j << " " << k << endl;
           }else{
              map[j][W-1-k] = now + 1 ;
               //cout << j << " " << W-1-k << endl;
           }
           
           count++ ;//ok
           if(a[now] <= count){
               now++ ;
               count = 0 ;
           }
        }
        
    }


    for(ll j = 0 ; j < H ; j++){
        for(ll k= 0 ; k < W ; k++){
            cout << map[j][k] << " " ;
        }
        cout << endl;
    }
    return 0;
}