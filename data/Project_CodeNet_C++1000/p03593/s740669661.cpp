#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string>a(h);
    vector<int>moji(26,0);
    for(int i=0;i<h;i++)cin >> a[i];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            moji[(int)(a[i][j]-'a')]++;
        }
    }
    bool chk;
    int limitOdd = 0;
    int limitEven = 0;
    if(h%2==0 && w%2==0){
    }else if(h%2 == 0){
        limitEven = h/2;
    }else if(w%2==0){
        limitEven = w/2;
    }else{
        limitEven = h/2 + w/2;
        limitOdd = 1;
    }
    // cout << "before"<<endl;
    // cout << limitEven << " "<<limitOdd << endl;

    for(int i=0;i<26;i++){
        if(moji[i]!=0){
            if(moji[i]%2 != 0)limitOdd--;
            else if(moji[i]%4 != 0)limitEven--;
        }
    }
    if(limitOdd >=0 && limitEven >= 0 && limitEven%2==0)chk = true;
    else chk = false;


    // cout << "after"<<endl;
    // cout << limitEven << " "<<limitOdd << endl;

    if(chk)cout<<"Yes"<<endl;
    else cout << "No"<<endl;


    // for(int i=0;i<26;i++){
    //     cout << (char)('a'+i )<< ":" << moji[i]<<endl;
    // }
}
