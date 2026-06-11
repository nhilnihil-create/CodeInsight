#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll h,w;cin>>h>>w;
    map<char,ll> m;
    rep(i,0,h){
        rep(j,0,w){
            char c;cin>>c;
            m[c]++;
        }
    }
    if(h!=1&&w!=1){
    if(h%2==0&&w%2==0){
        for(auto i:m){
            if(i.second%4!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    else if(h*w%2==1){
        int cn=0,cn4=0;
        for(auto i:m){
            if(i.second%2==1)cn++;
            cn4+=i.second/4;
        }
        if(cn!=1||cn4<((h-1)/2*(w-1)/2)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    else{
        int cn4=0;
        for(auto i:m){
            if(i.second%2==1){
                cout<<"No"<<endl;
                return 0;
            }
            cn4+=i.second/4;
        }
        if(h%2==1){
            if(cn4<((h-1)/2*w/2)){
                cout<<"No"<<endl;
                return 0;
            }
        }
        else{
            if(cn4<((w-1)/2*h/2)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    }
    else{
        if(h*w%2==0){
            for(auto i:m){
                if(i.second%2==1){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        else{
            ll cn=0;
            for(auto i:m){
                if(i.second%2==1)cn++;
            }
            if(cn!=1){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"Yes"<<endl;
}





