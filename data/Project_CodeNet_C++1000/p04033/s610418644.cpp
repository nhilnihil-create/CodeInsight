#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
int main(){
    int a, b;
    cin >> a >> b;
    if(a<=0 && b>=0){
        cout << "Zero";
    }
    else if(a<0 && b<0){
        if((b-a+1)&1)
            cout << "Negative";
        else
            cout << "Positive";
    }
    else if(a>0 && b>0){
        cout << "Positive";
    }
    else{
        if((-a)&1)
            cout << "Negative";
        else
            cout << "Positive";
    }
}