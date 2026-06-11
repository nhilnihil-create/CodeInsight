#include <bits/stdc++.h>
using namespace std;

int N;
int L[210];

int main(){
    cin>>N;

    for (int i = 0; i < 2*N; i++)
    {
        cin>>L[i];
    }
    
    sort(L,L+2*N);

    int ans = 0;
    for (int i = 0; i < 2*N; i+=2)
    {
        ans += L[i];
    }
    
    cout << ans << endl;
    return 0;
}
