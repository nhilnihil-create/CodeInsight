#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int mi=int(to_string(n).size());
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            mi = min(max(int(to_string(i).size()), int(to_string(n/i).size())),mi);
        }
    }
    cout << mi << '\n';
}
