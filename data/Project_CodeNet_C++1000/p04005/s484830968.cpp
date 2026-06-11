#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A, B, C;
    cin>>A>>B>>C;

    if (A%2==0 || B%2==0 || C%2==0) cout<<0<<endl;
    else                            cout<<min(min(A*B, B*C), C*A)<<endl;
}
