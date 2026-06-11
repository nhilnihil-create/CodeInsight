#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#define rep(i,N) for(int i=0;i<N;i++)

long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;
int N;


void show_ans(int ans[]){
    for(int i=1;i<=N;i++){
            if(ans[i]==0){
                cout<<'S';}
            else{
                cout<<'W';}
    }
    return;
}
int main(){

cin>>N;

string s;
cin>>s;

int  head[2]={0,1};
int  next[2]={0,1};
rep(i,2)rep(k,2){
    int ans[N+2];
    ans[1]=head[i];
    ans[2]=next[k];
    for(int l=2;l<N;l++){
        if(s[l-1]=='o' && ans[l]==0){
            ans[l+1]=ans[l-1];
        }
        else if(s[l-1]=='o' && ans[l]==1){
            ans[l+1]=1-ans[l-1];
        }

        if(s[l-1]=='x' && ans[l]==0){
            ans[l+1]=1-ans[l-1];
        }
        else if(s[l-1]=='x' && ans[l]==1){
            ans[l+1]=ans[l-1];
        }
    }

    ans[N+1]=ans[1];
    ans[0]=ans[N];
    bool cor=true;
    for(int l=1;l<=N;l++){
        if(s[l-1]=='o'){
            if(ans[l]==0){
                if(ans[l+1]!=ans[l-1])cor=false;
            }
            if(ans[l]==1){
                if(ans[l-1]==ans[l+1])cor=false;
            }
        }

        else if(s[l-1]=='x'){
            if(ans[l]==1){
                if(ans[l-1]!=ans[l+1])cor=false;
            }
            if(ans[l]==0){
                if(ans[l-1]==ans[l+1])cor=false;
            }
        }
    }
    if(cor){
        show_ans(ans);
        return 0;
    }
}
cout<<"-1"<<endl;
 return 0;
}
/*
6
ooxoox

SSSWWS

3
oox

-1


10
oxooxoxoox

SSWWSSSWWS
*/