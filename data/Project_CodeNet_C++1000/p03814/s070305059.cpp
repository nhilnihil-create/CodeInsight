#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long index_a, index_z;

    for(long long i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            index_a = i;
            break;
        }
    }

    for(long long i = s.size(); i >= 0; i--){
        if(s[i] == 'Z'){
            index_z = i;
            break;
        }
    }

    cout << index_z - index_a + 1 << endl;

    return 0;
}