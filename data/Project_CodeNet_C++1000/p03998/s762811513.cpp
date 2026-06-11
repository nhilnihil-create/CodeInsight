#include <bits/stdc++.h>
using namespace std;

int a1(string &a,string &b,string &c){
    if (a.size()==0){
        cout << "A";
        return 0;
    }
    else {
        if (a[0]== 'a'){
            a.erase(a.begin());
            return 1;
        }
        else if (a[0]== 'b'){
            a.erase(a.begin());
            return 2;
        }
        else {
            a.erase(a.begin());
            return 3;
        }
    }
}
int b1(string &a,string &b,string &c){
    if (b.size()==0){
        cout << "B";
        return 0;
    }
    else {
        if (b[0]== 'a'){
            b.erase(b.begin());
            return 1;
        }
        else if (b[0]== 'b'){
            b.erase(b.begin());
            return 2;
        }
        else {
            b.erase(b.begin());
            return 3;
        }
    }
}
int c1(string &a,string &b,string &c){
    if (c.size()==0){
        cout << "C";
        return 0;
    }
    else {
        if (c[0]== 'a'){
            c.erase(c.begin());
            return 1;
        }
        else if (c[0]== 'b'){
            c.erase(c.begin());
            return 2;
        }
        else {
            c.erase(c.begin());
            return 3;
        }
    }
}

int main() {
    string a,b,c;
    cin >> a >> b >> c;
    int r = a.size() + b.size() + c.size();
    int which=1;
    for (int t=0;t<=r;t++){
        if (which==1){
            which=a1(a,b,c);
        }
        else if (which==2){
            which=b1(a,b,c);
        }
        else if (which==3){
            which=c1(a,b,c);
        }
        else {
            return 0;
        }
    }
    // cout << a << b << c;
    
}