#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    vector <long long int> a(3*N);

    for(int i=0;i<3*N;i++){
        cin >> a.at(i);
    }

    long long int ans=0;

    sort(a.begin(),a.end());

    for(int i=0;i<N;i++){
        ans += a.at(3*N-2*i-2);
    }

    cout << ans << endl;
}