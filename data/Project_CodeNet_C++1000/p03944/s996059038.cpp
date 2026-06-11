#include "bits/stdc++.h"
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;++i)
#define END(x) (*(x.end()-1))
#define INF INT_MAX / 2

using namespace std;
typedef long long ll;


template<typename T>
T gcd(T a, T b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

template<typename T>
T lcm(T a,T b){
    return a/gcd(a,b)*b;
}

int main(void){
    int w,h,n,x,y,a;
    cin>>w>>h>>n;
    int up=h,bottom=0,left=0,right=w;
    rep(i,n){
        cin>>x>>y>>a;
        switch(a){
        case 1:
            left=max(left,x);
            break;
        case 2:
            right=min(right,x);
            break;
        case 3:
            bottom=max(bottom,y);
            break;
        case 4:
            up=min(up,y);
            break;
        }
    }
    cout<<max(0,up-bottom)*max(0,right-left);
}
/*

*/
