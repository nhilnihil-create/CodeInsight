#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)
#define INF (1<<18)


int main() {
    int n;
    cin>>n;
    vector<int> a(8,0);
    int over = 0;
    rep(i,n){
        int b;
        cin>>b;

        if(1 <= b && b <=399) a[0]++;
        rep2(j,1,8){
            if(j*400 <= b && b <= j*400+399) a[j]++;
        }
        if(3200 <= b) over++;
    }

    int color = 0;
    rep(i,8){
        if(a[i] != 0) color++;
    } 
    
    int min, max;

    if(over >= 1 && color == 0){
       min = 1; 
    }
    else{
        min = color;
    }
    max = color + over;

    cout<<min<<" "<<max<<endl;

    return 0;
}