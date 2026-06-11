#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool Check(int a,int b){
    if(a > 0){
        if(b > 0) return true;
        else return false;
    }
    else{
        if(b == 0) return true;
        else return false;
    }
}
int main(){
    
    string S; cin >> S;
    int len = S.size();
    int data[4];
    for(int i=0;i<4;i++) data[i] = 0;
    for(int i=0;i<len;i++){
        if(S[i] == 'N') data[0]++;
        else if(S[i] == 'W') data[1]++;
        else if(S[i] == 'S') data[2]++;
        else data[3]++;
    }
    
    if(Check(data[0],data[2]) && Check(data[1],data[3]) ) cout << "Yes" << endl;
    else cout << "No" << endl;
}