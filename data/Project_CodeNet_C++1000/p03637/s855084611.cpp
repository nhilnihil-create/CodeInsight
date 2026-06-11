#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int twokosuu=0,fourkosuu=0,kasu=0;
    for(int i=0;i<n;i++){
        long long a;
        cin >> a;
        if(a%4==0)fourkosuu++;
        else if(a%2==0)twokosuu++;
        else kasu++;
    }
    //cout << fourkosuu << twokosuu << kasu << endl;
    if(twokosuu==0){
        if(kasu<=fourkosuu+1)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        kasu += 1;
        if(kasu<=fourkosuu+1)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}