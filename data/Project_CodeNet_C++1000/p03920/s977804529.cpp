#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define MOD 1000000007
//#define INF 1145141919810893//810114514
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define Taka(s) s?cout << "Takahashi" << endl:cout << "Aoki" << endl
#define int long long 


signed main(){
    int N;
    cin >> N;
    int d=0,e=0;
    
    while(N>0){
        d=0,e=0;
        while(e<N){
            d++;
            e+=d;
        }
        cout << d<<endl;
        N-=d;
    }
	return 0;
}
