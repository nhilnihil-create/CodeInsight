#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long A[N];
    for (int i=0; i<N; i++) cin >> A[i];
    long long sum1=0;
    long long count1=0;
    for (int i=0; i<N; i++){
       sum1+=A[i];
       if (i%2==0 && sum1<=0){
           count1+=(1-sum1);
           sum1=1;
       }
       if (i%2==1 && sum1>=0){
           count1+=(sum1+1);
           sum1=-1;
       }
    }
    long long sum2=0;
    long long count2=0;
    for (int i=0; i<N; i++){
        sum2+=A[i];
        if (i%2==0 && sum2>=0){
            count2+=(sum2+1);
            sum2=-1;
        }
        if (i%2==1 && sum2<=0){
            count2+=(1-sum2);
            sum2=1;
        }
    }
    cout << min(count1, count2) << endl;
    
}