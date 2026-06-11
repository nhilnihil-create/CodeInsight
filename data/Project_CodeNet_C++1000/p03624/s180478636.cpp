#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF const ll INF = 1001001001;
#define PI const ld PI = 3.14159265358979323846;



int main() {
    string S;
    int a[30];
    rep(i,'z'-'a'+1){
        a[i]=0;
    }
    cin>>S;
    rep(i,S.size()){
        a[S[i]-'a']++;
    }
    string min_c;
    rep(i,'z'-'a'+1){
        if(a[i]==0){
            min_c=(char)(i+'a');
            break;
        }
        else if(i=='z'-'a'){
            min_c="None";
        }
    }
    cout<<min_c<<endl;
    return 0;
}