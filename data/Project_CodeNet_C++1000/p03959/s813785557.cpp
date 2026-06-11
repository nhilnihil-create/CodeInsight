#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    int t;
    long long int MOD=1e9+7;
    long long int res=1;
    cin >> N;

    vector<long long int> T(N+2),A(N+2);
    for(int i=1;i<=N;i++){
        cin >>t;
        T[i]=t;
    }
    for(int i=1;i<=N;i++){
        cin >>t;
        A[i]=t;
    }
    for (int i=1;i<=N;i++){
        bool t = T[i]!=T[i-1];
        bool a = A[i]!=A[i+1];
        if( a||t){
            if((a && A[i]>T[i]) || (t && T[i]>A[i])) res=0;
        } else {
            res = (res*min(A[i],T[i]))%MOD;
        }
    }
    cout << res << endl;
}
