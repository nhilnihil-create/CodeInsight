#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    char animals[2] = {'S', 'W'};

    for(int i=0; i<4; i++){
        string str = "";
        str += animals[i/2];
        str += animals[i%2];
        for(int j=2; j<n; j++){
            if (s[j-1] == 'o' ^ str[j-1] == 'S' ^ str[j-2] == 'S'){
                str += 'S';
            }else{
                str += 'W';
            }
        }

        if (s[n-1] == 'o' ^ str[n-1] == 'S' ^ str[n-2] == 'S'){
            if (str[0] != 'S'){
                continue;
            }
        }else{
            if (str[0] != 'W'){
                continue;
            }
        }

        if (s[0] == 'o' ^ str[0] == 'S' ^ str[n-1] == 'S'){
            if (str[1] == 'S'){
                cout << str << endl;
                return 0;
            }
        }else{
            if (str[1] == 'W'){
                cout << str << endl;
                return 0;
            }
        }
    }
    printf("-1\n");
}