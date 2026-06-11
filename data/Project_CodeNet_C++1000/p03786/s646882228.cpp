#include<iostream>
#include<algorithm>

using namespace std;

long long A[100005], pf[100005];

int main(){
    int N, ans = 1, count = 0;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1);

    pf[1] = A[1];
    for(int i=1; i<N; i++){
        if(i > 1)
            pf[i] = pf[i-1] + A[i];
        if(pf[i]*2 >= A[i+1]) count++;
        else count = 0;
    }

    cout << ans + count << endl;
}