#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        int a,b;
        cin >> a >> b;
        if(a<0 && b<0){
        if(abs(a)%2==0 && abs(b)%2==0){
            cout << "Negative" << endl;
        }
        
        if(abs(a)%2==1 && abs(b)%2==1){
            cout << "Negative" << endl;
        }
        
        if(abs(a)%2==1 && abs(b)%2==0){
            cout << "Positive" << endl;
        }
        
        if(abs(a)%2==0 && abs(b)%2==1){
            cout << "Positive" << endl;
        }
        }
        else if(a>0 && b>0){
            cout << "Positive" << endl;
        }
        else{
            cout << "Zero" << endl;
        }

        return 0;
    }