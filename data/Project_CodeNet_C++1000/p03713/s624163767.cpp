#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(void){
    ll h,w; cin >> h >> w;
    ll ans = pow(10,11);
    vector<ll>s(3);
    for(int i=1;i<h;i++){
        s[0]= i * w;
        ll rest_h = h - i;
        if(rest_h%2==0 || w%2==0){
            s[1] = rest_h*w/2;
            s[2] = rest_h*w/2;
        }else{
            if(rest_h < w){
                s[1] = (w/2) * rest_h;
                s[2] = (w/2 + 1) * rest_h;
            }else{
                s[1] = (rest_h/2) * w;
                s[2] = (rest_h/2 + 1) * w;
            }
        }
        ll tmp = *max_element(s.begin(),s.end())-*min_element(s.begin(),s.end());
        if(tmp < ans) ans = tmp;
        // cout << i << ' ' <<  ans << endl;
    }
    
    for(int i=1;i<w;i++){
        s[0]= i * h;
        ll rest_w = w - i;
        if(rest_w%2==0 || h%2==0){
            s[1] = rest_w*h/2;
            s[2] = rest_w*h/2;
        }else{
            if(rest_w < h){
                s[1] = (h/2) * rest_w;
                s[2] = (h/2 + 1) * rest_w;
            }else{
                s[1] = (rest_w/2) * h;
                s[2] = (rest_w/2 + 1) * h;
            }
        }
        ll tmp = *max_element(s.begin(),s.end())-*min_element(s.begin(),s.end());
        if(tmp < ans) ans = tmp;
        // cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}