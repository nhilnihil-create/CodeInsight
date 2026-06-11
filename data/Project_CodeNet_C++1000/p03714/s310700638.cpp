#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

static const long long inf (1e18);

int main(){
    long long N;
    cin >> N;
    priority_queue<long long, vector<long long>, greater<int> > que1;
    priority_queue<long long> que2;

    long long A[3*N+1];

    for(long long i=1;i<=N*3;i++){
        cin >> A[i];
    }

    long long sum1[2*N+1];
    sum1[0]=0;

    for(long long i=1;i<=N;i++){
        sum1[i]=sum1[i-1]+A[i];
        que1.push(A[i]);
    }

    for(long long i=N+1;i<=2*N;i++){
        sum1[i]=sum1[i-1]+A[i];
        que1.push(A[i]);
        sum1[i]-=que1.top();
        que1.pop();
    }

    reverse(A+1,A+N*3+1);

    long long sum2[2*N+1];
    sum2[0]=0;

    for(long long i=1;i<=N;i++){
        sum2[i]=sum2[i-1]+A[i];
        que2.push(A[i]);
    }

    for(long long i=N+1;i<=2*N;i++){
        sum2[i]=sum2[i-1]+A[i];
        que2.push(A[i]);
        sum2[i]-=que2.top();
        que2.pop();
    }

    long long ans=-inf;

    for(long long i=N;i<=2*N;i++){
        ans=max(ans,sum1[i]-sum2[N*3-i]);
    }
    
    cout << ans << endl;

}