#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    ll x,y;
    cin>>x>>y;
    if(x>=0&&y>=0&&x<y){
        cout<<y-x<<endl;
    }
    else if(x>=0&&y>=0&&x>y){
        if(y==0)cout<<x-y+1<<endl;
        else cout<<x-y+2<<endl;
    }
    else if(x<0&&y<0&&x>y){
        cout<<x-y+2<<endl;
    }
    else if(x<0&&y<=0&&x<y){
        if(y==0)cout<<-x<<endl;
       else cout<<abs(x)-abs(y)<<endl;
    }
    else {
        cout<<abs(abs(x)-abs(y))+1<<endl;
    }


}


 

