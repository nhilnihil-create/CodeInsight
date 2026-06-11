#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;

using namespace std;

int main() {
    ll N;
    string s;
    cin >> N >>s;
    for(int i = 0; i < 4; i++){
        bool isSheep[N];
        for(int i= 0; i < N; i++){
            isSheep[i] = false;
        }
        if(i & (1 << 0)){
            isSheep[0] = true;
        }
        if(i  < (1 << 1)){
            isSheep[1] = true;
        }
        for(int j = 2; j < N; j++){
            if(isSheep[j - 1]){
                //羊
                if(s[j - 1] == 'x'){
                    isSheep[j] = !isSheep[j - 2];
                }else{
                    isSheep[j] = isSheep[j - 2];
                }
            }else{
                //狼
                if(s[j - 1] == 'x'){
                    isSheep[j] = isSheep[j - 2];
                }else{
                    isSheep[j] = !isSheep[j - 2];
                }
            }
        }
        //Validate
        bool validate1 = false;
        if(isSheep[N - 1]){
            //羊
            if(s[N - 1] == 'x'){
                validate1 = isSheep[N - 2] == !isSheep[0];
            }else{
                validate1 = isSheep[N - 2] == isSheep[0];
            }
        }else{
            //狼
            if(s[N - 1] == 'x'){
                validate1 = isSheep[N - 2] == isSheep[0];
            }else{
                validate1 = isSheep[N - 2] == !isSheep[0];
            }
        }
        bool validate2 = false;
        if(isSheep[0]){
            //羊
            if(s[0] == 'x'){
                validate2 = isSheep[N - 1] == !isSheep[1];
            }else{
                validate2 = isSheep[N - 1] == isSheep[1];
            }
        }else{
            //狼
            if(s[0] == 'x'){
                validate2 = isSheep[N - 1] == isSheep[1];
            }else{
                validate2 = isSheep[N - 1] == !isSheep[1];
            }
        }
        if(validate1 && validate2){
            for(int x = 0; x < N; x++){
                if(isSheep[x]){
                    cout << "S";
                }else{
                    cout << "W";
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
