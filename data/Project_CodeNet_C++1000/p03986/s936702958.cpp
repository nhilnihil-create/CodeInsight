#include <iostream>
#include <string>
using namespace std;

int main(){
    string x;
    cin >> x;
    int ans = 0;
    int tnokori = 0;
    for(int i = x.length()-1; i >= 0; i--){
        if(x[i] == 'S'){
            if(tnokori > 0){
                tnokori--;
            }else{
                ans++;
            }
        }else{
            tnokori++;
        }
    }
    cout << ans+tnokori << endl;
    return 0;
}