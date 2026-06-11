#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
    ll N,A,B,i,r=0;
    cin >> N >> A >> B;
    vector<int> X(N);

    for(i=0; i<N; i++)
        cin >> X.at(i);
    
    for(i=0; i<N-1; i++)
        if((X.at(i+1)-X.at(i))*A < B)
            r += (X.at(i+1)-X.at(i))*A;
        else
            r += B;
    
    cout << r << endl;
}