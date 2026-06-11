#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "No" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl


const int MAX_N=200010;
int n,dat[4*MAX_N-1];
int Seg_init(int n_){
    n=1;
    while(n<n_)n*=2;
    for(int i=0;i<2*n-1;++i)dat[i]=0;
    return n;
}
int Seg_calc(int a,int b){
    return (a+b)%3;
}
void Seg_update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=Seg_calc(dat[2*k+1],dat[2*k+2]);
    }
}
/*
int Seg_query(int a,int b,int k,int l,int r){
    cout << a MM b MM k MM l MM r << endl;
    //外からはSeg_query(a,b,0,0,n)で呼ぶ
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return dat[k];
    int vl=Seg_query(a,b,2*k+1,l,(l+r)/2);
    int vr=Seg_query(a,b,2*k+2,(l+r)/2,r);
    return Seg_calc(vl,vr);
}*/

int Seg_query(int a,int b){
    int R=0;
    a+=n;b+=n;
    
    while(a<b){
        if(a%2==1){
            R=Seg_calc(dat[a-1],R);
            a++;
        }
        if(b%2==1){
            b--;
            R=Seg_calc(R,dat[b-1]);
        }
        a/=2;b/=2;
    }
    
    
    return R;
}

signed main(void){
    string S,T;
    int Q;
    int A[114514],B[114514],C[114514],D[114514];
    int G[114514],H[114514];
    
    cin >> S >> T;
    cin >> Q;
    REP(i,Q){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--;B[i]--;C[i]--;D[i]--;
    }
    
    //Aを1、Bを2、O(=AB)を0と扱う
    
    //Sをセグる
    Seg_init(S.size());
    REP(i,S.size()){
        Seg_update(i,(S[i]=='A'?1:2));
    }
    REP(i,Q){
        G[i]=Seg_query(A[i],B[i]+1);
    }
    //Tをセグる
    Seg_init(T.size());
    REP(i,T.size()){
        Seg_update(i,(T[i]=='A'?1:2));
    }
    REP(i,Q){
        H[i]=Seg_query(C[i],D[i]+1);
    }
    
    //REP(i,Q){cout << G[i] MM H[i] << endl;}
    
    REP(i,Q){
        if(G[i]==H[i]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

