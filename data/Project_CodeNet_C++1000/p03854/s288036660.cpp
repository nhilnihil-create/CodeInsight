#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int main(){
    string s;
    cin >> s;
    
    vector<string> moji(4);
    moji[0]="dream"; moji[1]="erase"; moji[2]="dreamer"; moji[3]="eraser";
    rep(i,4) reverse(moji[i].begin(),moji[i].end());
    reverse(s.begin(),s.end());
    int num=0;
    while(1){
        int temp=num;
        rep(j,5){
            if(s[num+j]!=moji[0][j]) break;
            if(j==4) num+=5;
        }
        rep(j,5){
            if(s[num+j]!=moji[1][j]) break;
            if(j==4) num+=5;
        }
        rep(j,7){
            if(s[num+j]!=moji[2][j]) break;
            if(j==6) num+=7;
        }
        rep(j,6){
            if(s[num+j]!=moji[3][j]) break;
            if(j==5) num+=6;
        }
        if(num==s.size()) break;
        if(num==temp){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}