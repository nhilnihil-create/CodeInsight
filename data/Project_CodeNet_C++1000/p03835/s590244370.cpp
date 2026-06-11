#include <iostream>
using namespace std;
int main(){
    int k,s;
    cin >> k >> s;
    int cnt = 0;
    for(int i = 0; i < k+1; i++){
        for(int j = 0; j < k+1;j++){
            if(0 <= s-i-j && s-i-j < k+1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}