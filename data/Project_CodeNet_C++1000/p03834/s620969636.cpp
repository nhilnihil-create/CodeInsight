#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    string s;
    cin >> s;
    string a[3];
    int j = 0;
    for(int i = 0; i < 19; i++) {
        if(s[i] == ',') {
            i++;
            j++;
        }
        a[j] += s[i];
    }
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    return 0;
}