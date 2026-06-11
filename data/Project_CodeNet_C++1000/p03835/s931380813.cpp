#include <iostream>
using namespace std;
int main(){
    int k, s;
    cin >> k >> s;
    int ans = 0;
    for(int x=0; x<k+1; x++){
        for(int y=0; y<k+1; y++){
            int z = s - x - y;
            if(0<=z && z<=k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}