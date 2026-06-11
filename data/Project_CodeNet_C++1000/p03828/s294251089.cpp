#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
    int n; cin >> n;
    vector<int> prime(n, 0);
    for (int i=n; i>1; i--){//n!をiで回す
        //cout << "i is " << i << endl;
        int n_copy=i;
        for (int j=2; j*j<=n; j++){//iを素因数分解
            while(n_copy%j==0){
                n_copy/=j;
                //cout << "n_copy is " << n_copy << endl;
                prime.at(j-2)++;//vectorは2origin（0, 1は素数でないため）
            }
        }
        if (n_copy>1) prime.at(n_copy-2)++;
    }
    long long count=1;
    for(int i=0; i<n-1; i++){
        //cout << i+2 << ":" << prime.at(i) << endl;
        count*=prime.at(i)+1;
        count%=MOD;
    }
    cout << count << endl;
    return 0;
}