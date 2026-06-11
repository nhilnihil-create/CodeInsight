#include<iostream>
using namespace std;
typedef long long ll;
const int MAX_N = 1e5+5;
int main(){
    ll n; cin >> n;
    ll a_sum = 0, n_sum = n*(n+1) / 2;
    ll A[MAX_N];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        a_sum += A[i];
    }
    if(a_sum % n_sum != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll times_0 = a_sum / n_sum;
    ll times_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if((A[i] - A[((i+1 == n)? 0 : i+1)] + times_0) % n != 0 ||( A[i] - A[((i+1 == n)? 0 : i+1)] + times_0) < 0) {
            cout << "NO" << endl;
            return 0;
        }
        times_1 += (A[i] - A[((i+1 == n)? 0 : i+1)] + times_0) / n;
    }
    if(times_1 == times_0){
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}