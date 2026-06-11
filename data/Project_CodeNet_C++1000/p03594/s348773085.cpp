#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;

int main(){
    int H,W,d;cin>>H>>W>>d;
    char t[2][2]={{'R','G'},{'B','Y'}};
    REP(i,H){ 
        REP(j,W) printf("%c",t[(i+j)/d%2][(500+i-j)/d%2]);
        printf("\n");
    }
}