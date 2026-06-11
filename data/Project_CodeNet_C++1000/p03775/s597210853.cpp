#include <bits/stdc++.h>
using namespace std;

int F(long int A,long int B){
    int da=0,db=0;

    while(A!=0){
        da ++;
        A = A/10;
    }

    while(B!=0){
        db ++;
        B = B/10;
    }

    return max(da,db);
}

int main() {
    long int N;
    cin >> N;

    int ans=F(1,N);

    for(long int i=1;i<sqrt(N)+1;i++){
        if(N%i==0){
            if(F(i,N/i)<ans){
                ans = F(i,N/i);
            }
        }
    }

    cout << ans << endl;
}