#include <bits/stdc++.h>
using namespace std;

int mygcd(int x,int y){
    if(x <= y){
        if(x == 0)
            return y;
        else
            return mygcd(y%x,x);      
    }else{
        if(y == 0)
            return x;
        else
        {
            return mygcd(y,x%y);
        }
        
    }
}

int main(){
    string S;
    cin >> S;
    int n=0,s=0,w=0,e=0,ns=0,we=0;

    for(int i = 0;i < S.size();i++){
        if(S.at(i) == 'N')
            n++;
        else if(S.at(i) == 'S')
            s++;
        else if(S.at(i) == 'W')
            w++;
        else
            e++;
    }
    if(mygcd(n,s) == 0)
        ns = 1;
    else
        ns = n * s /mygcd(n,s);
    if(mygcd(w,e) == 0 )
        we = 1;
    else
        we = w * e /mygcd(w,e);

    if(ns > 0 && we > 0)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;




}