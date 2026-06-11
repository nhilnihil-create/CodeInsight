#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int i;
    for(i=0;i<s2.size();i++){
        cout << s1[i] << s2[i];
    }
    if(s1.size()!=s2.size()){
        cout << s1[i];
    }
    cout << endl;
}

