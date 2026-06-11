#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
int A[111111];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    sort(A,A+N);reverse(A,A+N);


    deque<pint>d;
    d.pb({A[N-1],(A[N-1]-1+N-1)%2==0});
    for(int i=N-2;i>=0;i--){
        if(d.size()>=2){
            d.front().fi--;
            d.back().fi++;
            if(d.front().fi==0)d.pop_front();
        }
        if(A[i]!=A[i+1]){
            int f=(A[i]-1+i)%2==0;
            if(d.back().se==f){
                d.back().fi+=A[i]-A[i+1];
            }
            else{
                if((A[i+1]-1+i)%2==f){
                    d.back().fi--;
                    if(d.front().fi==0)d.pop_front();
                    d.pb({A[i]-A[i+1]+1,f});
                }
                else{
                    d.pb({A[i]-A[i+1],f});
                }
            }
        }
    }

    if(d[0].se)cout<<"Second"<<endl;
    else cout<<"First"<<endl;
    return 0;
}
