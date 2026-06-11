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
    int n;
    cin >> n;
    if (n < 1200) {
        cout << "ABC";
    }
    else {
        cout << "ARC";
    }

    
}

    
