#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int CheckIncre(vector<int> V, int i){
    int num;
    if(V.at(i+1)>V.at(i)) num=1;
    else if(V.at(i+1)==V.at(i)) num=0;
    else if(V.at(i+1)<V.at(i)) num=-1;
    return num;
}

int main(){
    int N; cin>>N;
    vector<int> A(N);
    rep(n,0,N) cin>>A.at(n);

    if(N==1){cout<<1<<endl;exit(0);}

    int ans=1;
    int incre=CheckIncre(A,0);
    rep(n,0,N-1){
        int _incre=CheckIncre(A,n);
        if(incre*_incre==-1){
            ans++;
            n++;
            if(n<N-1) incre=CheckIncre(A,n);
        }
        else if(incre==0) incre=_incre;
    }

    cout<<ans<<endl;
}