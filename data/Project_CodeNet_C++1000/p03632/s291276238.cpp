#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >>d;
    int A[101]={0};
    int B[101]={0};
    int i;
    for(i=a;i<b;i++){
        A[i]=1;
    }
    for(i=c;i<d;i++){
        B[i]=1;
    }
    int v=0;
    for(i=0;i<101;i++){
        if((A[i]==1)&&(B[i]==1)){
            v++;
        }
    }
    cout << v << endl;

    return 0;
}