#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    string s,t;
    cin >> s;
    t.resize(N);
    ll i,j;
    t[0]='S';
    t[1]='S';
    for(i=0;i<4;i++){
        if(i==0){t[0]='S';t[1]='S';}
        if(i==1){t[0]='S';t[1]='W';}
        if(i==2){t[0]='W';t[1]='S';}
        if(i==3){t[0]='W';t[1]='W';}
        for(j=1;j<N-1;j++){
            if((t[j]=='S'&&s[j]=='o')||(t[j]=='W'&&s[j]=='x'))t[j+1]=t[j-1];
            if((t[j]=='W'&&s[j]=='o')||(t[j]=='S'&&s[j]=='x'))t[j+1]=((t[j-1]=='S')?'W':'S');
        }
        ll flag1=0,flag2=0;
        if((t[N-1]=='S'&&s[N-1]=='o')||(t[N-1]=='W'&&s[N-1]=='x')){
            if(t[0]==t[N-2])flag1=1;
        }
        if((t[N-1]=='W'&&s[N-1]=='o')||(t[N-1]=='S'&&s[N-1]=='x')){
             if(t[0]!=t[N-2])flag1=1;
        }
        if((t[0]=='S'&&s[0]=='o')||(t[0]=='W'&&s[0]=='x')){
            if(t[N-1]==t[1])flag2=1;
        }
        if((t[0]=='W'&&s[0]=='o')||(t[0]=='S'&&s[0]=='x')){
             if(t[N-1]!=t[1])flag2=1;
        }
        if(flag1&&flag2){cout << t << endl;return 0;}
    }
    cout << -1;
    return 0;
}