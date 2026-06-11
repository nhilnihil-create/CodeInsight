#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ansnum = -1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int count = 0;
        int tmp = i;
        while(tmp % 2 == 0){
            count++;
            tmp /= 2;
        }
        if(ansnum < count){
            ansnum = count;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}