#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<char>v(s.size());
    int index=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='B'){
            v[index]=s[i];
            index++;
        }
        else{
            if(index>0)
                index--;
        }
    }
    for(int i=0;i<index;i++)
    {
        cout<<v[i];
    }
}