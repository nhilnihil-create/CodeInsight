#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    if(s==t){
        cout << n << endl;
        return 0;
    }
    int tmp=0;
    for(int i=1; i<n; i++){
        if(t.substr(0,i)==s.substr(n-i,i)){
            tmp = i;
        }
    }
    cout << 2 * n - tmp << endl;
    return 0;
}