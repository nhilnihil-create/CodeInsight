#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i=1; 2*(i+1)<=n; i++){
        if(s.substr(0,(n-2*i)/2)==s.substr((n-2*i)/2,(n-2*i)/2)){
            cout << n-i*2 << endl;
            return 0;
        }
    }
    return 0;
}