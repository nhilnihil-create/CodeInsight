#include <bits/stdc++.h>
#define ll long long int
#define NMAX 1000005

using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

ll n, val, i, x, nrMutat;
struct numar{
    ll val;
    ll index;
};
numar N[NMAX];
int criteriu(numar a, numar b){
    if(a.val < b.val)
        return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> x;
        N[i].val = x;
        N[i].index = i;
        }
    sort(N+1, N+n+1, criteriu);
    for(i=1; i<=n; i++){
        if((i%2) != (N[i].index%2))
            ++nrMutat;
    }
    cout << nrMutat/2 << '\n';
    return 0;
}