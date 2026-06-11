#include <bits/stdc++.h>
using namespace std;
int OK(string S){
    if(S.size()%2!=0) return -1;
    string s1="",s2="";
    for(int i=0;i<S.size()/2;i++){
        s1 += S.at(i);
    }
    for(int i=S.size()/2;i<S.size();i++){
        s2 += S.at(i);
    }
    //cout << "s1 = " << s1 << " s2 = " << s2 << endl;
    if(s1==s2) return S.size();
    return -1;
}
int main(){
    string S;
    cin >> S;
    int N = S.size();
    for(int i=0;i<N;i++){
        S.pop_back();
        //cout << S << endl;
        if(OK(S)!=-1){
            cout << OK(S) << endl;
            return 0;
        }
    }
    return 0;
}