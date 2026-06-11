#include"bits/stdc++.h"
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 10000000009
#define MX 200005
#define MOD 1000000007

using namespace std;
int n;
char men(char a[],char r,int i){
    if(r=='o'){
        if(a[i]=='S'){
            if(a[(i+1)%n]=='S')a[(i+2)%n]='S';
            else a[(i+2)%n]='W';
        }else{
            if(a[(i+1)%n]=='S')a[(i+2)%n]='W';
            else a[(i+2)%n]='S';
        }
    }else{
        if(a[i]=='S'){
            if(a[(i+1)%n]=='S')a[(i+2)%n]='W';
            else a[(i+2)%n]='S';
        }else{
            if(a[(i+1)%n]=='S')a[(i+2)%n]='S';
            else a[(i+2)%n]='W';
        }
    }
    return a[(i+2)%n];
}

int main(){
    cin>>n;
    char a[MX],b[MX],c[MX],d[MX];
    a[0]='S';a[1]='S';
    b[0]='S';b[1]='W';
    c[0]='W';c[1]='S';
    d[0]='W';d[1]='W';
    char r0;
    cin>>r0;
    rep(i,n-2){
        char r;
        cin>>r;
        men(a,r,i);
        men(b,r,i);
        men(c,r,i);
        men(d,r,i);
    }
    char r1;
    cin>>r1;
    if('S'==men(a,r1,n-2)&&'S'==men(a,r0,n-1))cout<<a;
    else if('S'==men(b,r1,n-2)&&'W'==men(b,r0,n-1))cout<<b;
    else if('W'==men(c,r1,n-2)&&'S'==men(c,r0,n-1))cout<<c;
    else if('W'==men(d,r1,n-2)&&'W'==men(d,r0,n-1))cout<<d;
    else cout<<-1<<endl;
    return 0;
}