#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<int>> mat;

int main(){
    int N;cin>>N;
    vec a(300010),S(300010);
    S[0]=0;
    for(int i=1;i<=3*N;i++){
        cin>>a[i];
        S[i]=S[i-1]+a[i];
    }
    vec L(100010),R(100010);
    //L[i]:a_1からa_(N+i)までの中で大きいN個の総和
    //R[i]:a_(2N+1-i)からa_3Nまでの中で小さいN個の総和
    priority_queue<ll,vec,greater<ll>> pqL;
    for(int i=1;i<=N;i++)
        pqL.push(a[i]);
    L[0]=S[N];
    for(int j=1;j<=N;j++){
        ll l=pqL.top();
        if(a[N+j]>l){
            pqL.pop();
            pqL.push(a[N+j]);
            L[j]=L[j-1]+a[N+j]-l;
        }
        else L[j]=L[j-1];
    }
    priority_queue<ll> pqR;
    for(int i=1;i<=N;i++)
        pqR.push(a[2*N+i]);
    R[0]=S[3*N]-S[2*N];
    for(int j=0;j<N;j++){
        ll l=pqR.top();
        if(a[2*N-j]<l){
            pqR.pop();
            pqR.push(a[2*N-j]);
            R[j+1]=R[j]-l+a[2*N-j];
        }
        else R[j+1]=R[j];
    }
    ll ans=-pow(10,18);
    for(int i=0;i<=N;i++)
        ans=max(ans,L[i]-R[N-i]);
    
    cout<<ans<<endl;
    return 0;
}