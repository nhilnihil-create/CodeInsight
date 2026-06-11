#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n;cin>>n;
    string s;cin>>s;
    char c[100010];
    int ok=0;
    rep(i,0,4){
        ok=1;
        if(i==0){c[0]='S',c[1]='S';}
        else if(i==1){c[0]='S',c[1]='W';}
        else if(i==2){c[0]='W',c[1]='S';}
        else if(i==3){c[0]='W',c[1]='W';}
        rep(j,1,n-1){
            if(s[j]=='o'){
                if(c[j]=='S'&&c[j-1]=='S')c[j+1]='S';
                else if(c[j]=='W'&&c[j-1]=='S')c[j+1]='W';
                else if(c[j]=='S'&&c[j-1]=='W')c[j+1]='W';
                else if(c[j]=='W'&&c[j-1]=='W')c[j+1]='S';
            }
            else{
                if(c[j]=='S'&&c[j-1]=='S')c[j+1]='W';
                else if(c[j]=='W'&&c[j-1]=='S')c[j+1]='S';
                else if(c[j]=='S'&&c[j-1]=='W')c[j+1]='S';
                else if(c[j]=='W'&&c[j-1]=='W')c[j+1]='W';
            }
        }
        if(s[n-1]=='o'&&c[n-1]=='S'&&c[n-2]!=c[0])ok=0;
        else if(s[n-1]=='o'&&c[n-1]=='W'&&c[n-2]==c[0])ok=0;
        else if(s[n-1]=='x'&&c[n-1]=='S'&&c[n-2]==c[0])ok=0;
        else if(s[n-1]=='x'&&c[n-1]=='W'&&c[n-2]!=c[0])ok=0;
        if(s[0]=='o'&&c[0]=='S'&&c[n-1]!=c[1])ok=0;
        else if(s[0]=='o'&&c[0]=='W'&&c[n-1]==c[1])ok=0;
        else if(s[0]=='x'&&c[0]=='S'&&c[n-1]==c[1])ok=0;
        else if(s[0]=='x'&&c[0]=='W'&&c[n-1]!=c[1])ok=0;
        if(ok){
            rep(i,0,n)cout<<c[i];
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
    







