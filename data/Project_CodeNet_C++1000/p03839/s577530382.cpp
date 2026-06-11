#include<iostream>

using namespace std;

long long pf[100005], arr[100005], nplus[100005];

int main(){
    int N, K;
    cin >> N >> K;

    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        if(arr[i] > 0) nplus[i] = nplus[i-1] + arr[i];
        else nplus[i] = nplus[i-1];
    }

    for(int i=1; i<=K; i++) pf[1]+= arr[i];

    for(int i=2; i<=N-K+1; i++) pf[i] = pf[i-1] + arr[i+K-1] - arr[i-1];

    long long maks = 0;
    for(int i=1; i<=N-K+1; i++){
        long long temp;
        if (pf[i] < 0) temp = nplus[i-1] + nplus[N] - nplus[K+i-1] ;
        else temp = pf[i] + nplus[i-1] + nplus[N] - nplus[K+i-1] ;

        if(temp > maks) maks = temp;
    }

    cout << maks << endl;

}