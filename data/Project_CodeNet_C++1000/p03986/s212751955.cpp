#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<char> vec = {'x'};
    char tmp;
    while(cin >> tmp){
        if(tmp=='S'){
            vec.push_back('S');
        }
        else if(tmp=='T'){
            if(vec.back()=='S'){
                vec.pop_back();
            }
            else{
                vec.push_back('T');
            }
        }
    }
    cout << vec.size() -1;
}

