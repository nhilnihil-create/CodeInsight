#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr2(i,s,n) for (int i = (n-1); i>=(int)(s);i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Grid = vector<vector<int>>;
const ll INF = 10011032323450010;
const ld PI = 3.14159265358979323846;



int main() {
     
    int N;
    cin>>N;
    vector<vector<int>> A(N,vector<int>(2));
    rep(i,N){
        cin>>A[i][0];
    }
    A[0][1]=0;
    int count=1;
    rep2(i,1,N){
        if(A[i-1][1]==0){
            
            if(A[i][0]>A[i-1][0]){
                A[i][1]=1;

            }
            else if(A[i][0]<A[i-1][0]){
                A[i][1]=-1;
            }
            else{
                A[i][1]=0;
            }
        }
        else if(A[i-1][1]==1){
            if(A[i][0]>=A[i-1][0]){

                
                A[i][1]=1;
            }
            else{
                count++;
                A[i][1]=0;
                

            }
        }
        else{
            if(A[i][0]<=A[i-1][0]){
                A[i][1]=-1;
            }
            else{
                count++;
                A[i][1]=0;
            }
        }
    }
    cout<<count<<endl;

return 0;
}