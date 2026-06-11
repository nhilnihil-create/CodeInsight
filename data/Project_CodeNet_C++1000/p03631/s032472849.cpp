#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n;cin>>n;
    string s = to_string(n);
    int len = s.size();
    for(int i =0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            cout<<"No"<<endl;
            return 0;
        }

    }
    cout<<"Yes"<<endl;
    return 0;

}