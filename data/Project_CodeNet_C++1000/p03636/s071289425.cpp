#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    string result="";
    result+=s[0];
    int length=s.size()-2;
    stack<int>st;
    while(length!=0){
        st.push(length%10);
        length/=10;
    }
    while(!st.empty()){
        result+=st.top()+'0';
        st.pop();
    }
    result+=s[s.size()-1];
    cout<<result;
}