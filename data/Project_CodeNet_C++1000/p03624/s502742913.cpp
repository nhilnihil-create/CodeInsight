#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    string s = "abcdefghijklmnopqrstuvwxyz";
    string str;
    cin >> str;
    set<char> st;

    for(int i=0;i<s.size();i++){
        st.insert(s[i]);
    }

    for(int i=0;i<str.size();i++){
      st.erase(str[i]);
    }

    if(st.size()==0){
        cout << "None" << endl;
    }else{
        cout << (*st.begin()) << endl; 
    }
}
