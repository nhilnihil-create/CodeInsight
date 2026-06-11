#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int saidaikouyakusuu(int a,int b){
    if(b==0) return a;
    return saidaikouyakusuu(b,a%b);
}
int saisyoukoubaisuu(int a,int b){
    return a*b/saidaikouyakusuu(a,b);
}
int n,m,cnt=0,aa[220000],ans=0,ab[220];
pair<int,int> pp[220000];
string s,ss[220000];
char c;
queue<int> que;
signed main(){
    cin>>s>>ss[0];
    if(s==ss[0]){
        cout<<"EQUAL"<<endl;
    }elif(s.size()>ss[0].size()){
        cout<<"GREATER"<<endl;
    }elif(s.size()<ss[0].size()){
        cout<<"LESS"<<endl;
    }else{
        rep(i,s.size()){
            if(s[i]>ss[0][i]){
                cout<<"GREATER"<<endl;
                return 0;
            }elif(s[i]<ss[0][i]){
                cout<<"LESS"<<endl;
                return 0;
            }
        }
        cout<<"EQUAL"<<endl;
    }
}