#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int a,b,c,ans=0,tmp_a,tmp_b,tmp_c;
  	cin >> a >> b >> c;
    if(a==b&&a==c&&!(a%2)){
        cout << -1 << endl;
        return 0;
    }
    while((!(a%2))&&(!(b%2))&&(!(c%2))){
        ans++;
        tmp_a=a/2;
        tmp_b=b/2;
        tmp_c=c/2;
        a=tmp_b+tmp_c;
        b=tmp_a+tmp_c;
        c=tmp_a+tmp_b;
    }
    cout << ans << endl;
}
