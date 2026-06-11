#include<iostream>
#include<set>
using namespace std;

int main(){
    string s;
    set<char> c;
    cin>>s;
    for(int i=0;i<(int)s.length();i++) c.insert(s[i]);

    for(char i='a';i<='z';i++){
        if(c.find(i)==c.end()){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
}