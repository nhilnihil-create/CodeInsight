#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n;
    string s, t, v = "SW";
    cin >> n >> s;
    t = string(n, '?');
    for(int j=0;j<4;j++){
        t[0] = v[j/2];
        t[1] = v[j%2];
        for(int i=2;i<n+2;i++){
            int i1 = (i-1)%n, i2 = (i-2)%n;
            if((t[i1] == t[i2] && s[i1] == 'o') || (t[i1] != t[i2] && s[i1] == 'x')) t[i%n] = 'S';
            else t[i%n] = 'W';
        }
        if(t[0] == v[j/2] && t[1] == v[j%2]){
            cout << t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
