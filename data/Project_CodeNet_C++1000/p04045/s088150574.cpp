#include <bits/stdc++.h>

using namespace std;

int d[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < K ; i++){
        int temp;
        cin >> temp;
        d[temp] = 1;
    }

    for(int i = N ; i < 1000000 ; i++){
        int temp = i;
        bool v = false;
        while(temp > 0){
            int digit = temp % 10;
            temp /= 10;
            if(d[digit]){
                v = false;
                break;
            }
            v = true;
        }

        if(v){
            cout << i << "\n";
            return 0;
        }
    }
}