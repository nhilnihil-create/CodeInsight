#include <bits/stdc++.h>
using namespace std;


#define MOD (long long) (1e9 + 7);

int main(){
    long long n;
    int avail = 0;

    cin >> n;

    long long res = 1;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        avail++;

        while((avail - 1) * 2 >= x){
            res = res * avail % MOD;
            avail--;
        }
    }

    while(avail > 0){
        res = res * avail % MOD;
        avail--;
    }

    cout << res << endl;
    return 0;
}
