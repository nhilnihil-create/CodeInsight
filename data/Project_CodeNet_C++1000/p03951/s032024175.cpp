#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL<<60;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP2(i,m,n) for(int i=m;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    int n;
    string s,t;
    cin >>n;
    cin>>s;
    cin>>t;

    int tmp=0;
    int ans=-1;
    REP2(i,1,n+1){
        if(s.substr(n-i,i)==t.substr(0,i)){
            tmp=i;
        } 
       
    }
    
    
    
    cout<<2*n-tmp<<endl;
}

