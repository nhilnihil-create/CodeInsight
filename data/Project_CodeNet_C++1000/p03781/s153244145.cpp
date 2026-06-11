#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(), (a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(), (a).end())

int main(){
    int64_t x;
    cin>>x;
    int i=1;
    int ans = 0;
    while(1){
        ans += i;
        if(ans>=x){
            break;
        }
        i++;
    }
    cout<<i<<endl;
}