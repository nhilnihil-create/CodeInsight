#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,k,t,big=0;
    cin >> k >> t;
    vector<int> a(t);
    for(i=0;i<t;i++){
        cin >> a.at(i);
        if(i==0)big=a.at(i);
        if(big<a.at(i))big=a.at(i);
    }
    if(k/2>=big){cout << 0 << endl;}
    else{
        cout << k-2*(k-big)-1 << endl;
    }

    return 0;
}