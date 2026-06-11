#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    int size = s.size() ;
    string new_s;
    for(int i=0;i<size;i++){
        if(i%2==0){
            new_s.push_back(s[i]) ;
        }
    }
    cout << new_s << endl;
}