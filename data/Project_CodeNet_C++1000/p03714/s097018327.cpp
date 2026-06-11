#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<int> a(3*N);
    for( int i = 0; i < 3*N; ++i ) cin >> a[i];


    priority_queue<long long, vector<long long>, greater<int>> firstHalf;
    priority_queue<long long> secondHalf;
    vector<long long> sumFirstHalf(N+1), sumSecondHalf(N+1);
    for( int i = 0; i < N; ++i ){
        firstHalf.push( a[i] );
        sumFirstHalf[0] += a[i];
    }
    for( int i = 2*N; i < 3*N; ++i ){
        secondHalf.push( a[i] );
        sumSecondHalf[N] += a[i];
    }

    // first half について分割部 i についての最大和を求める
    for( int i = N; i < 2*N; ++i ){
        int tmp = firstHalf.top();
        if( tmp < a[i]){
            firstHalf.pop();
            firstHalf.push( a[i] );
            sumFirstHalf[i-N+1] = sumFirstHalf[i-N] - tmp + a[i];
        }else sumFirstHalf[i-N+1] = sumFirstHalf[i-N];
    }
    // second half について分割部 i についての最小和を求める
    for( int i = 2*N-1; i >= N; --i ){
        int tmp = secondHalf.top();
        if( tmp > a[i]){
            secondHalf.pop();
            secondHalf.push( a[i] );
            sumSecondHalf[i-N] = sumSecondHalf[i-N+1] - tmp + a[i];
        }else sumSecondHalf[i-N] = sumSecondHalf[i-N+1];
    }

    long long ans = sumFirstHalf[0] - sumSecondHalf[0];
    for( int i = 1; i <= N; ++i ) ans = max( ans, sumFirstHalf[i] - sumSecondHalf[i] );
    cout << ans << endl;

    return 0;
}