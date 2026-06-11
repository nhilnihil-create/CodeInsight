#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 100000000000000009
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl


signed main(){
    int N,M;
    int A[114514],B[114514];
    vector<int> V[114514];
    vector<int> Sum,Ans;
    cin >> N >> M;
    REP(i,M){
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
        V[A[i]].push_back(B[i]);
        V[B[i]].push_back(A[i]);
    }
    bool cont[114514]={};
    REP(i,114514){cont[i]=false;}
    
    Sum.push_back(A[0]);
    Sum.push_back(B[0]);
    cont[A[0]]=true;
    cont[B[0]]=true;
   
    
    while(1){
        int E=Sum.size();
        bool c=true;
        REP(i,V[Sum[E-1]].size()){
            if(cont[V[Sum[E-1]][i]]==false){
                c=false;
                Sum.push_back(V[Sum[E-1]][i]);
                cont[V[Sum[E-1]][i]]=true;
                break;
            }
        }
        if(c==true){
            break;
        }
    }
    int E=Sum.size();
    REP(i,E){
        Ans.push_back(Sum[E-1-i]);
    }
    
    while(1){
        int E=Ans.size();
        bool c=true;
        REP(i,V[Ans[E-1]].size()){
            if(cont[V[Ans[E-1]][i]]==false){
                c=false;
                Ans.push_back(V[Ans[E-1]][i]);
                cont[V[Ans[E-1]][i]]=true;
                break;
            }
        }
        if(c==true){
            break;
        }
    }
    
    cout << Ans.size() << endl;
    REP(i,Ans.size()){
        if(i!=0)cout << " ";
        cout << Ans[i]+1;
    }
    cout << endl;
    
    return 0;
}
