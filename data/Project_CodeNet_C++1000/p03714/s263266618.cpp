#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<queue>

using namespace std;
const long long INF=9223372036854775800;

int main(){
    int N;
    long long a[300000];
    cin>>N;
    for(int i=0;i<3*N;i++){
        cin>>a[i];
    }
    priority_queue<long long,vector<long long>,greater<long long> > queL;
    priority_queue<long long> queR;
    long long tmpL=0;
    long long tmpR=0;
    for(int i=0;i<N;i++){
        queL.push(a[i]);
        queR.push(a[2*N+i]);
        tmpL+=a[i];
        tmpR+=a[2*N+i];
    }
    long long ansL[300000];//ansL[i]でiまでの数列の上N個の和
    long long ansR[300000];//ansR[i]でi以上の数列の下N個の和
    ansL[N]=tmpL;
    ansR[2*N]=tmpR;
    for(int i=N+1;i<=2*N;i++){
        queL.push(a[i-1]);
        long long now=queL.top(); queL.pop();
        tmpL=tmpL+a[i-1]-now;
        ansL[i]=tmpL;
    }
    for(int i=2*N-1;i>=N;i--){
        queR.push(a[i]);
        long long now=queR.top(); queR.pop();
        tmpR=tmpR+a[i]-now;
        ansR[i]=tmpR;
    }
    long long ans=-INF;
    for(int i=N;i<=2*N;i++){
        ans = max(ans, ansL[i]-ansR[i]);
    }
    cout<<ans<<endl;
    return 0;
}
