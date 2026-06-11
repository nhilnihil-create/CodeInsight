#include<bits/stdc++.h>
using namespace std;

//typedef
typedef unsigned int UINT;
typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef tuple<LL, LL, LL> TLL3;
typedef tuple<LL, LL, LL, LL> TLL4;
typedef set<LL, greater<LL> > setdownLL;
#define PQ priority_queue
typedef PQ<LL, vector<LL>, greater<LL> > pqupLL;
//container utill
#define ALL(v) (v).begin(),(v).end()
#define CR [](auto element1, auto element2){return element1>element2;}
#define LB lower_bound
#define UP upper_bound
#define PB push_back
#define MP make_pair
#define MT make_tuple
//constant
#define PI 3.141592653589793

template<class Abel> struct BIT{
    vector<Abel> dat;
    long long n;

    BIT(long long n_origin, Abel SUM_UNITY):dat(n_origin +1,SUM_UNITY), n(n_origin){}

    Abel sum_from_first(long long i){//[1,i]
        Abel s=0;
        while(i>0){
            s+=dat[i];
            i-= (i&(-i));
        }
        return s;
    }

    Abel sum(long long i, long long j){//[i,j)
        Abel vl = sum_from_first(i-1);
        Abel vr = sum_from_first(j-1);
        return vr-vl;
    }

    void add(long long i, Abel x){
        while(i <= n){
            dat[i] += x;
            i += (i&(-i));
        }
    }
};

int main(){
    //input
    LL N,K;
    cin >> N >> K;
    long long i;
    LL A[N+1];
    A[0]=0;
    for(i=1; i<=N; i++){
        cin >> A[i];
        A[i]-=K;
    }

    //calc
    long long n=N+1;
    long long a[n+1];
    vector<pair<long long, long long> > a_ind;
    a_ind.resize(n);
    for(i=0; i<n; i++){
        if(i==0){
            a[i]=A[i];
        }else{
            a[i]=A[i]+a[i-1];
        }
        a_ind[i]=make_pair(a[i],i);
    }
    sort(a_ind.begin(),a_ind.end());
    for(i=0; i<n; i++){
        a[a_ind[i].second]=i+1;
    }
    long long ans=0;
    BIT<long long> BIT(n,0);
    for(i=0; i<n; i++){
        ans += i-BIT.sum_from_first(a[i]);
        BIT.add(a[i],1);
    }

    //output
    cout << ((N+1LL)*N)/2LL-ans << endl;
    system("pause");
    return 0;
}