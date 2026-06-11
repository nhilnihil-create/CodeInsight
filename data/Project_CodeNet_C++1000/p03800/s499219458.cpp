#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    string s;
    cin>>N>>s;
    
    //SW
    string S[4]={"SS","SW","WS","WW"};
    for(int i=0;i<4;i++){
        for(ll j=1;j<N-1;j++){
            if(S[i][j]=='S'){
                if(S[i][j-1]=='S'){//SS
                    if(s[j]=='o'){
                        S[i]=S[i]+'S';
                    }else{
                        S[i]=S[i]+'W';
                    }
                }else{//WS
                    if(s[j]=='o'){
                        S[i]=S[i]+'W';
                    }else{
                        S[i]=S[i]+'S';
                    }
                }
            }else{
                if(S[i][j-1]=='S'){//SW
                    if(s[j]=='o'){
                        S[i]=S[i]+'W';
                    }else{
                        S[i]=S[i]+'S';
                    }
                }else{//WW
                    if(s[j]=='o'){
                        S[i]=S[i]+'S';
                    }else{
                        S[i]=S[i]+'W';
                    }
                }
            }
        }
        bool ok=true;
        if(s[0]=='o'){
            if(S[i][0]=='S'){
                if(S[i][N-1]!=S[i][1])ok=false;
            }else{
                if(S[i][N-1]==S[i][1])ok=false;
            }
        }else{
            if(S[i][0]=='S'){
                if(S[i][N-1]==S[i][1])ok=false;
            }else{
                if(S[i][N-1]!=S[i][1])ok=false;
            }
        }
        if(s[N-1]=='o'){
            if(S[i][N-1]=='S'){
                if(S[i][N-2]!=S[i][0])ok=false;
            }else{
                if(S[i][N-2]==S[i][0])ok=false;
            }
        }else{
            if(S[i][N-1]=='S'){
                if(S[i][N-2]==S[i][0])ok=false;
            }else{
                if(S[i][N-2]!=S[i][0])ok=false;
            }
        }
        if(ok){
            cout<<S[i]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    
    return 0;
}
