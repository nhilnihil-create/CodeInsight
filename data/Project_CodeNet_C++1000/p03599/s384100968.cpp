#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
#define rep(i,n) for (ll i=0;i<n;i++)
using namespace std;

void solve(){

}

// int search(int q,int w,int e){
//     int ans=0;
//     rep(i,(e + q - 1)/q + 1){
//         rep(j,(e + w - 1)/w + 1){
//             if ((i*q+w*j)<=e){
//                 ans=max(ans,i*q+w*j);
//             }
            
//         }
//     }
//     return ans;
// }

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f ;

    ll ansx = 0,ansy = 10000;

    // double ans = 0;

    // rep(i,f+1){
    //     rep(j,f+1){
    //         double W = c*i  + d*j;

    //         if(W<=f){
    //             int tmp = W*100 / e;
    //             if(tmp>f-W){
    //                 continue;
    //             }
    //             bool p = false;
    //             rep(k,f/100+1){
    //                 if((tmp-k*a*100)%(b*100)==0){
    //                     p = true;
    //                 }
    //             }
    //             if(!p) continue;
    //             if((double) W/(tmp+W) > ans){
    //                 ans = (double) W/(tmp+W);
    //                 ansx = W;
    //                 ansy  = tmp;
    //             }
    //         }


    //     }
    // }



    rep(i,31){
        rep(j,31){
            rep(k,1501){
                rep(l,1501){
                    int s = (i*a + j*b)*100 + c*k + d*l;
                    // double q = (c*k + d*l)  / (double)s; 
                    if(s>f) continue;
                    if(c*k + d*l > e*(i*a + j*b)) continue;

                    if(ansx*(i*a + j*b)*100 <= ansy*(c*k + d*l)){
                        ansx = c*k + d*l;
                        ansy = (i*a + j*b)*100;
                    }
                }
            }

        }
    }


    // int s;
    // s=f/(100+e);
    // // cout <<s <<endl;
    // int x;
    // x=search(a,b,s);
    // // cout << x <<endl;

    // int y;
    // y=search(c,d,x/e);

    cout << ansx + ansy << " " << ansx << endl;
    return 0;
}