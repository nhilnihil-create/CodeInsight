#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> A(3);
    for(int i=0;i<3;i++) cin >> A[i];

    int res = 0;
    vector<int> tmp(3);
    bool wataseru = true;

    while(wataseru&&A[0]%2==0&&A[1]%2==0&&A[2]%2==0){
        
        for(int i=0;i<3;i++) tmp[i]=A[i]/2;
        for(int i=0;i<3;i++){
            A[i]=0;
            for(int j=0;j<3;j++){
                if(i!=j) A[i]+=tmp[j];
            }
        }

        res++;

        if(A[0]==A[1]&&A[1]==A[2]&&A[0]%2==0){
            wataseru = false;
            res = -1;
        }
    }

    cout << res << endl;


    return 0;
}