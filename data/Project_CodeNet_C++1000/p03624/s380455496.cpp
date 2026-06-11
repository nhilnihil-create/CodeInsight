#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string S;
    cin>>S;
    string result = "None";
    map<char,int> d;
    for(int i = 0;i<S.size();i++){
        d[S[i]] += 1;
    }
    for(char i = 'a';i<='z';i++){
        if(d[i]==0){
            result = i;
            break;
        }
    }
    cout<<result<<endl;
}