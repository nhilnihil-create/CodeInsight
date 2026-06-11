#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<unordered_set>

using namespace std;




vector<int> prime_sieve(int n)
{
    int* arr = new int[n+1];
    
    int i, p;
    for (i = 0; i <= n; ++i) {
        arr[i] = i;
    }
    for (i = 2; i <= n; ++i) {
        if (arr[i] != 0) {
            for (p = arr[i] * arr[i]; p <= n; p += arr[i]) {
                arr[p] = 0;
            }
        }
    }
    vector<int> primes;
    for (i = 2; i <= n; ++i) {
        if (arr[i] != 0) {
            primes.push_back(arr[i]);
        }
    }
    return primes;
}

int min(int a, int b)
{
    return a < b ? a : b;
}


int main()
{
    long long n,a,b;
    cin >> n >> a >> b;
    vector<int> arr;
    int i,ele;
    for (i = 0; i < n; ++i){
        cin >> ele;
        arr.push_back(ele);

    }
    long long ans = 0;
    for (i = 1; i < n; ++i) {
        ans += min(b, (arr[i] - arr[i - 1]) * a);
    }
    cout << ans;


    
}