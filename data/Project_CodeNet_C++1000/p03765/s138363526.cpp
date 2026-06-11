#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

class segmenttree{
    private:
    int n;
    long long identity = 0;//単位元
    std::vector<long long> dat;
    public:
    
    void init(int N){
        n=1;
        while(n<N)n*=2;
        dat.clear();
        for(int i=0;i<2*n-1;++i){
            dat.push_back(identity);
        }
    }
    
    long long calc();
    
    void update(int k,long long a){
        k+=n-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=calc(dat[2*k+1],dat[2*k+2]);
        }
    }
    
    long long query(long long a,long long b){
        a+=n;
        b+=n;
        long long R=0;
        while(a < b){
            if(a % 2 == 1){
                R = calc(R, dat[a - 1]);
                a += 1;
            }
            a /= 2;
            if(b % 2 == 1){
                b -= 1;
                R = calc(R, dat[b - 1]);
            }
            b /= 2;
        }
        return R;
    }
    
    long long calc(long long a,long long b){
        return (a+b)%3;
    }
    
};


int main(){
    
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
    
    segmenttree Sseg,Tseg;
    
    //Sをセグる
    Sseg.init(S.size());
    REP(i,S.size()){
        Sseg.update(i,(S[i]=='A'?1:2));
    }
    REP(i,Q){
        G[i]=Sseg.query(A[i],B[i]+1);
    }
    //Tをセグる
    Tseg.init(T.size());
    REP(i,T.size()){
        Tseg.update(i,(T[i]=='A'?1:2));
    }
    REP(i,Q){
        H[i]=Tseg.query(C[i],D[i]+1);
    }
    
    //REP(i,Q){cout << G[i] <<" "<< H[i] << endl;}
    
    REP(i,Q){
        if(G[i]==H[i]){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}