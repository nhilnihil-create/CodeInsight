#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int cnt_five=0,cnt_seven=0;
void judge(int n){
    if(n==5)cnt_five++;
    else if(n==7)cnt_seven++;
}
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c;
    cin>>a>>b>>c;
    judge(a);
    judge(b);
    judge(c);
    if(cnt_five==2&&cnt_seven==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
