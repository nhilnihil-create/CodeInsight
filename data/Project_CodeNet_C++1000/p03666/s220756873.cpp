#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long int a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    for(int i=0; i<=n-1; i++){
        long long int xmin = c * (n-1-i) + (-d) * i;
        long long int xmax = d * (n-1-i) + (-c) * i;
        if(xmin <= b-a && b-a <= xmax){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}