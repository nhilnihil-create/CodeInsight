#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
string s;
char t[10][100005];
int main(void){
    cin>>n>>s;
    t[0][0]='S';
    t[1][0]='S';
    t[2][0]='W';
    t[3][0]='W';
    if(s[0]=='o'){
        t[0][1]='S';
        t[0][n-1]='S';
        t[1][1]='W';
        t[1][n-1]='W';
        t[2][1]='S';
        t[2][n-1]='W';
        t[3][1]='W';
        t[3][n-1]='S';
    }else{
        t[0][1]='S';
        t[0][n-1]='W';
        t[1][1]='W';
        t[1][n-1]='S';
        t[2][1]='S';
        t[2][n-1]='S';
        t[3][1]='W';
        t[3][n-1]='W';
    }
    for(int i=2;i<n-1;i++){
        for(int j=0;j<4;j++){
            if(s[i-1]=='o'){
                if(t[j][i-1]=='S'){
                    t[j][i]=t[j][i-2];
                }else{
                    if(t[j][i-2]=='S'){
                        t[j][i]='W';
                    }else{
                        t[j][i]='S';
                    }
                }
            }else{
                if(t[j][i-1]=='S'){
                    if(t[j][i-2]=='S'){
                        t[j][i]='W';
                    }else{
                        t[j][i]='S';
                    }
                }else{
                    t[j][i]=t[j][i-2];
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        bool k=false;
        bool l=false;
        if(s[n-2]=='o'){
            if(t[i][n-2]=='S'){
                if(t[i][n-1]==t[i][n-3]){
                    k=true;
                }
            }else{
                if(t[i][n-1]!=t[i][n-3]){
                    k=true;
                }
            }
        }else{
            if(t[i][n-2]=='S'){
                if(t[i][n-1]!=t[i][n-3]){
                    k=true;
                }
            }else{
                if(t[i][n-1]==t[i][n-3]){
                    k=true;
                }
            }
        }
        if(s[n-1]=='o'){
            if(t[i][n-1]=='S'){
                if(t[i][n-2]==t[i][0]){
                    l=true;
                }
            }else{
                if(t[i][n-2]!=t[i][0]){
                    l=true;
                }
            }
        }else{
            if(t[i][n-1]=='S'){
                if(t[i][n-2]!=t[i][0]){
                    l=true;
                }
            }else{
                if(t[i][n-2]==t[i][0]){
                    l=true;
                }
            }
        }
        if(k&&l){
            for(int j=0;j<n;j++){
                cout<<t[i][j];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

}

