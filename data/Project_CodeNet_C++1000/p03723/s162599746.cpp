#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int a,b,c;cin>>a>>b>>c;
    int cnt=0;
    while(1){
        if(a%2==0&(a==b&&b==c)){co(-1);return 0;}
        if(a%2==1||b%2==1||c%2==1){co(cnt);return 0;}
        int aa=a/2,bb=b/2,cc=c/2;
        a=bb+cc;b=aa+cc;c=aa+bb;
        cnt++;
    }
}