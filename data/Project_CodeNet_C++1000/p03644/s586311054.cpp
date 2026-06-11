#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main(){
    int n,box=0;
    cin >> n;
    int A[7] = {1,2,4,8,16,32,64};
    for(int i=0;i<7;i++){
        if(A[i]<=n){
            swap(A[i],box);
        }
    }
    cout << box;
    return 0;
}