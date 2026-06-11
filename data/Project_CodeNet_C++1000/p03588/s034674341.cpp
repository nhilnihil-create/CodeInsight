#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
typedef long long ll;
int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    vector<int>B(N);
    int max_a=0,b;
    rep(i,N){
        cin>>A[i]>>B[i];
        if(max_a<A[i]){
            max_a=A[i];
            b=B[i];
        }
    }
    cout<<max_a+b<<endl;


    return 0;
}