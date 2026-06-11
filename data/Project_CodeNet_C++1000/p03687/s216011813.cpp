/**
*    author:  souzai32
*    created: 02.08.2020 18:06:18
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    string s;
    cin >> s;
    int n=s.size();
    int ans=n,num,count=0;

    rep(i,26){
        num=0;
        count=0;
        rep(j,n){
            if(s.at(j)=='a'+i){
                num=max(count,num);
                count=0;
            }
            else count++;
            if(j==n-1) num=max(count,num);
        }
        //cout << num << endl;
        ans=min(ans,num);
    }

    cout << ans << endl;

    return 0;
}