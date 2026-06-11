#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
    }
    
    vector<long long> nk = {K};
    for (int i = 0; i < 30; i++) {
        if (!(K & (1ll << i))) continue;
        
        nk.push_back((K & ~(1ll << i)) | ((1ll << i) - 1));
    }

    long long maxi = 0;
    for (long long ki: nk) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            bool ok = true;
            for (int k = 0; k < 30; k++) {
                if (!(ki & (1ll << k)) && (a.at(j) & (1ll << k))) ok = false;
            }   
            if (ok) sum += b.at(j);
        }
        maxi = max(maxi, sum);
    }
    cout << maxi << endl;
}