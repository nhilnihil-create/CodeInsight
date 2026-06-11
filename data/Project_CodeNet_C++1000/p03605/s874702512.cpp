#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string ans = "No";
    cin >> n;

    while(n > 0){
        int t;
        t = n%10;
        n /= 10;
        if(t == 9)ans = "Yes";
    }

    cout << ans << endl;

    return 0;
}