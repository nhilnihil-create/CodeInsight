#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){

    bool flag = false;
    int A,Z;
    string s;
    cin >> s;

    rep(i,s.size()){

        if(flag == false && s[i] == 'A'){
            A = i;
            flag = true;
        }

        if(s[i] == 'Z')
            Z = i;
    }
    
    cout << Z-A+1 <<endl;
    return 0;
}