#include<iostream>
#include<queue>
using namespace std;

int main(){
    //input
    long long N;
    cin >> N;
    long long a[3*N+1];
    long long i;
    for(i=1; i<=3*N; i++){
        cin >> a[i];
    }

    //calc
    priority_queue<long long> que_zen, que_kou;
    long long zen[3*N+1], kou[3*N+1];
    zen[N]=0;
    for(i=1; i<=N; i++){
        que_zen.push(-a[i]);
        zen[N]+=a[i];   
    }
    for(i=N+1; i<=2*N; i++){
        que_zen.push(-a[i]);
        zen[i]=zen[i-1]+a[i]-(-que_zen.top());
        que_zen.pop();
    }
    kou[2*N+1]=0;
    for(i=2*N+1; i<=3*N; i++){
        que_kou.push(a[i]);
        kou[2*N+1]+=a[i];
    }
    for(i=2*N; i>=N+1; i--){
        que_kou.push(a[i]);
        kou[i]=kou[i+1]+a[i]-que_kou.top();
        que_kou.pop();
    }
    long long ans=-10000000000000000;
    for(i=N; i<=2*N; i++){
        ans=max(ans,zen[i]-kou[i+1]);
    }

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}