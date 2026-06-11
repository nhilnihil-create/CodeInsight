#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    string x;
    cin >> x;
    int s=0,t=0;
    int ans=x.size();
    for(int i = 0; i < x.size()-1; i++) {
        if(x[i]=='S') s++;
        else t++;

        if(x[i]=='T' && x[i+1]=='S'){
            if(t>s){
                ans -= s*2;
                s=0;t=0;
            }
            else{
                ans -= t*2;
                s -= t;
                t=0;
            }
        }
    }

    if(x[x.size()-1]=='S') s++;
    else t++;
    if(t>s){
        ans -= s*2;
        s=0;t=0;
    }
    else{
        ans -= t*2;
        s -= t;
        t=0;
    }    

    cout << ans << endl;

    return 0;
}