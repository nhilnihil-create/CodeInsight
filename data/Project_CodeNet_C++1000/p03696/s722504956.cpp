#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll pointer=0;
    ll left_counter=0;
    for(int i=0; i<S.size(); i++){
        if(S[i]=='(') pointer++;
        else{
            if(pointer==0) left_counter++;
            else pointer--; 
        }
    }
    ll right_counter=pointer;

    string res="";
    for(int i=0; i<left_counter; i++){
        res+='(';
    }
    res+=S;
    for(int i=0;i<right_counter; i++){
        res+=')';
    }
    cout << res << endl;
}