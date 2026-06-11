#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    if(s1.size()>s2.size()){
        cout << "GREATER" << endl;
        return 0;
    }else if(s1.size()<s2.size()){
        cout << "LESS" << endl;
        return 0;
    }else{
        for(int i=0;i<s1.size();i++){
            int a = s1[i]-'0';
            int b = s2[i]-'0';
            if(a>b){
                cout << "GREATER" << endl;
                return 0;
            }else if(b>a){
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
}

