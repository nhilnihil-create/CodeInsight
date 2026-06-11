#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e15;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(3*n);
    vector<long long int> sum1(n+1), sum2(n+1);
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq1;
    priority_queue<long long int> pq2;
    for(int i=0; i<3*n; i++){
        cin >> a[i];
        if(i < n){
            sum1[0] += a[i];
            pq1.push(a[i]);
        }
        if(i >= 2*n){
            sum2[n] += a[i];
            pq2.push(a[i]);
        }
    }

    for(int i=0; i<n; i++){
        pq1.push(a[n+i]);
        sum1[i+1] = sum1[i] + a[n+i] - pq1.top();
        //cout << sum1[i+1] << " = " << sum1[i] << " + " << a[n+i] << " - " << pq1.top() << endl;
        pq1.pop();

        pq2.push(a[2*n-i-1]);
        sum2[n-i-1] = sum2[n-i] + a[2*n-i-1] - pq2.top();
        pq2.pop();
    }
    long long int ans = -INF;
    for(int i=0; i<=n; i++){
        //cout << sum1[i] << " " << sum2[i] << endl;
        ans = max(ans, sum1[i] - sum2[i]);
    }
    cout << ans << endl;
    return 0;
}