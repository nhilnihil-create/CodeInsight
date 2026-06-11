#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define vi vector<int>
int main() {
    int n;
    cin>>n;
    vi a(n,0);
    int now=0;
    int cnt=0;
    rep(i,n){
        cin>>a[i];
    }

    while(true){
        cnt++;
        if(a[now]==2){
            break;
        }else if(cnt>n){
            cnt=-1;
            break;
        }else{
            now = a[now]-1;
        }
    }
    cout<<cnt<<endl;
}