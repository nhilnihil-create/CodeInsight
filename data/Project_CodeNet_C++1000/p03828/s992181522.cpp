#include <math.h>

#include <iostream>
#include <vector>
using namespace std;

bool JudgePrime(int num) {
    if (num > 2) {
        if (num % 2 == 0)
            return false;
        else {
            bool is_prime = true;
            for (int i = 3; i < num; i++) {
                if (num % i == 0) is_prime = false;
            }
            if (!is_prime) return false;
            if (is_prime) return true;
        }
    } else
        return true;
}

void PrimeFact(vector<int>& prime, int num) {
    for (int i = 2; i <= num; i++) {
        if (JudgePrime(i)) {
            int num_c = num;
            int count = 0;
            bool div_fin = false;
            while (!div_fin) {
                if (num_c % i == 0) {
                    num_c /= i;
                    count++;
                } else
                    div_fin = true;
            }
            prime[i - 1] += count;
        }
    }
}

int main() {
    int n;
    int mod = pow(10, 9) + 7;
    cin >> n;
    vector<int> prime(n);
    long int total = 1;
    for (int i = 1; i <= n; i++) {
        PrimeFact(prime, i);
    }
    for (int i = 0; i < n; i++) {
        total = (total * (prime[i] + 1) % mod) % mod;
    }
    cout << total << endl;
    return 0;
}