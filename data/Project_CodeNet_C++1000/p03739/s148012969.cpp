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

int main(void)
{
    int N;
    cin >> N;

    vector<ll> A(N);
    REP(i,N){
        cin >> A[i];
    }

    //偶数番目を正
    ll ansA = 0;
    ll sumA = 0;
    REP(i,N){
        sumA += A[i];
        if(i%2 == 0){//偶数番目を正に
            if (sumA <= 0){
                ansA += (abs(sumA) + 1);
                sumA += (abs(sumA) + 1);
            }
        }
        else{//奇数番目を負に
            if (sumA >= 0){
                ansA += (abs(sumA) + 1);
                sumA -= (abs(sumA) + 1);
            }
        }
    }

    //奇数番目を正
    ll ansB = 0;
    ll sumB = 0;
    REP(i,N){
        sumB += A[i];
        if(i%2 != 0){//奇数番目を正に
            if (sumB <= 0){
                ansB += (abs(sumB) + 1);
                sumB += (abs(sumB) + 1);
            }
        }
        else{//偶数番目を負に
            if (sumB >= 0){
                ansB += (abs(sumB) + 1);
                sumB -= (abs(sumB) + 1);
            }
        }
    }

    cout << min(ansA,ansB) << endl;

    return 0;
}
