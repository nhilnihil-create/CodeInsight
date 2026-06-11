#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int flag = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i * (m - j) + j * (n - i) == k){
                flag = 1;
                break;
            }
        }
    }

    if(flag == 1){
        cout << "Yes" << endl; 
    }else{
        cout << "No" << endl;
    }
}