#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num[] = {1,2,4,8,16,32,64};
    
    for(int i=0;i<n;i++){
        if(n<num[i]){
            cout << num[i-1] << endl;
            break;
        }else if(n==num[i]){
            cout << num[i] << endl;
            break;
        }
    }
    
    return 0;
}