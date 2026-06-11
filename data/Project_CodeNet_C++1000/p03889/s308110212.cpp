#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=505,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S,T;cin>>S;
    T=S;
    reverse(all(T));
    
    for(int i=0;i<si(T);i++){
        if(T[i]=='b') T[i]='d';
        else if(T[i]=='d') T[i]='b';
        else if(T[i]=='p') T[i]='q';
        else T[i]='p';
    }
    
    if(S==T) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

