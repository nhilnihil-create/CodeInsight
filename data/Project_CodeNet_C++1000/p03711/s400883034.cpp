#include <bits/stdc++.h>
using namespace std;

bool isIn(int arr[], int n, int len){
    int flag = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] == n){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    int x, y, flag = 0, group1[7] = {1, 3, 5, 7, 8, 10, 12}, group2[4] = {4, 6, 9, 11}, group3[1] = {2};

    cin >> x >> y;

    if(isIn(group1, x, 7) && isIn(group1, y, 7)){
        flag = 1;
    }
    else if(isIn(group2, x, 4) && isIn(group2, y, 4)){
        flag = 1;
    }
    else if(isIn(group3, x, 1) && isIn(group3, y, 1)){
        flag = 1;
    }

    if(flag == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;

}




