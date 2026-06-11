#include <iostream>
#define N_MAX 1000000000
using namespace std;
int func(long long n){
    static int cnt = 0;
    if(cnt++ > 64)return -1;
    char ans;
    cout << "? " << n << endl;
    cin >> ans;
    if(ans == 'Y')return 1;
    return 0;
}
int main(void){
    long long left = (long long)N_MAX*10-1, right = (long long)N_MAX*100;
    while(left + 1 < right){
        long long mid = (left + right) / 2;
        if(func(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }

    while(right%10 == 0)right /= 10;

    if(right == 1){
        while(func(right*2) == 0){
            right *= 10;
        }
        cout << "! " << right << endl;
    }else{
        left = 10;
        right--;
        while(func(right*left) == 1){
            left *= 10;
        }
        left /= 10;
        right++;
        cout << "! " << right*left << endl;
    }

}
