#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int a,b;cin>>a>>b;
    int cnt=0;
    for(int i=a;i<=b;i++){
        cnt+= (i<0)?1:0;
        if(i==0){co("Zero");return 0;}
    }
    co((cnt%2==1)?"Negative":"Positive");
}