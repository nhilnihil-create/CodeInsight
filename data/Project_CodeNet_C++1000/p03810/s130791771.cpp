#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define fin "\n"


#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)

template <typename T>
inline void chmin(T &l,T r){l=min(l,r);}

template <typename T>
inline void chmax(T &l,T r){l=max(l,r);}

template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}

LL gcd(LL a,LL b){
    return (b==0)?a:gcd(b,a%b);
}

int f(int turn, LL sum, vector<LL> A){
    int one=0,two=0,odd=0,O=-1;
    int N=A.size();
    REP(i,N){
        if(A[i]==1)one++;
        else if(A[i]%2==0)two++;
        else odd++,O=i;
    }
    if(one){
        if((sum-N)%2==1)return turn;
        else return 1-turn;
    }
    else if(odd>=1&&(sum-N)%2==1)return turn;
    else if(odd==1){
        LL g=A[O]-1;
        REP(i,N)if(i!=O)g=gcd(g,A[i]);
        vector<LL> B=A;
        B[O]--;
        REP(i,N)B[i]/=g;
        return f(1-turn,(sum-1)/g,B);
    }
    else return 1-turn;
}
int main(){
    int N;
    cin>>N;
    LL sum=0;
    vector<LL> A(N);
    REP(i,N){
        cin>>A[i];
        sum+=A[i];
    }
    if(sum==N)cout<<"Second"<<endl;
    else 
    if(f(0,sum,A)==0)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}
