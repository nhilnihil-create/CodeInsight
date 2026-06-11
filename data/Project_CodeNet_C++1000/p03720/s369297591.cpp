#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,M,a,b;
    int rec[50];
    
    cin >> N >> M;

    rep(i,N)
        rec[i] = 0;

    rep(i,M){
        cin >> a >> b;
        rec[a-1]++;
        rec[b-1]++;
    }

    rep(i,N)
        cout << rec[i] << endl;

    
    return 0;
}