#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    string s; cin >> s;
    ll K; cin >> K;
    int N=s.size();
    for(int i=0;i<N;i++){
        ll res=('z'-s[i]);
        if(s[i]=='a') continue;
        if(K>=(res+1)){
            K-=(res+1);
            s[i]='a';
        }
    }

    ll res=K%26;
    for(int i=1;i<=res;i++){
        s[N-1]++;
        if((s[N-1]-'a')==26){
            s[N-1]='a';
        }
    }
    cout << s << endl;
}