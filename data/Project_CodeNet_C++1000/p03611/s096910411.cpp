#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

int chk(int x, int y){
    if (x == y-1){
        
    }  
}

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(100010);
    REP(i,N){
        cin >> A[i];
        if (A[i]>0)B[A[i]-1]++;
        B[A[i]]++;
        B[A[i]+1]++;
    }

    sort(ALL(B));
    reverse(ALL(B));

    cout << B[0] << endl;

    return 0;
}
