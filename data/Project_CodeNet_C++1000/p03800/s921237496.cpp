#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <complex>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

int n;
string s;

string str(string st){
    for(int i=1;i<=n;i++){
        if(s[i]=='o'){
            if(st[i]=='0'){
                st+=st[i-1];
            }
            else if(st[i-1]=='0') st+='1';
            else st+='0';
        }else{
            if(st[i]=='1'){
                st+=st[i-1];
            }
            else if(st[i-1]=='0') st+='1';
            else st+='0';
        }
    }
    if(st[0]==st[n] && (s[0]=='o'&&st[0]=='0'&&st[1]==st[n-1])) return st;
    if(st[0]==st[n] && (s[0]=='o'&&st[0]=='1'&&st[1]!=st[n-1])) return st;
    if(st[0]==st[n] && (s[0]=='x'&&st[0]=='0'&&st[1]!=st[n-1])) return st;
    if(st[0]==st[n] && (s[0]=='x'&&st[0]=='1'&&st[1]==st[n-1])) return st;
    else return "false";
}

int main(){
    cin >> n >> s;
    //0=sheep 1=wolf
    string res1="00",res2="01",res3="10",res4="11";
    if(str(res1)!="false"){
        string ans=str(res1);
        rep(i,n){
            if(ans[i]=='0') cout << 'S';
            else cout << 'W';
        }
        return 0;
    }
    if(str(res2)!="false"){
        string ans=str(res2);
        rep(i,n){
            if(ans[i]=='0') cout << 'S';
            else cout << 'W';
        }
        return 0;
    }
    if(str(res3)!="false"){
        string ans=str(res3);
        rep(i,n){
            if(ans[i]=='0') cout << 'S';
            else cout << 'W';
        }
        return 0;
    }
    if(str(res4)!="false"){
        string ans=str(res4);
        rep(i,n){
            if(ans[i]=='0') cout << 'S';
            else cout << 'W';
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
