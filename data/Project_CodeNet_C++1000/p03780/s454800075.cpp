#include<bits/stdc++.h>
using namespace std;
const int SIZE = 5001;
bool comp(int x,int y){
    return x > y;
}
int main(){
    long long n, k; cin >> n >> k;
    int A[SIZE];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A+n, comp);
    long long sum_A = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum_A + A[i] < k)
        {
            ans++;
        }
        else
        {
            ans = 0;
        }
        sum_A = (sum_A + A[i] >= k ? sum_A : sum_A+A[i]);
    }
    cout << ans << endl;
}