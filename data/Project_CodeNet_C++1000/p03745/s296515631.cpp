#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    int cnt=0;
    int state=0;
    int p;
    cin >> p;
    for(int i=1; i<n; i++){
        int now;
        cin >> now;
        if(state==0){
        if(p<now) state=1;
        else if(p>now) state=2;
    }
    else if(state==1){
        if(p>now){
            cnt++;
            state = 0;
        }
    }
    else if(state==2){
        if(p<now){
            cnt++;
            state = 0;
        }
    }
    p = now;
    }
    cout << cnt+1 << endl;
}