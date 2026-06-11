#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int h,w;
char s[105][105];
int main(void){
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>s[i][j];
        }
    }
    for(int i=0;i<=h+1;i++){
        s[i][0]='#';
        s[i][w+1]='#';
    }
    for(int i=0;i<=w+1;i++){
        s[0][i]='#';
        s[h+1][i]='#';
    }
    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    
}
