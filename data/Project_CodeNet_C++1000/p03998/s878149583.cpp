#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    a.push_back('E');
    b.push_back('E');
    c.push_back('E');
    char tmp = 'A';
    vector<int> l(3, 0);
    while(l[0] < (int)a.size() && l[1] < (int)b.size() && l[2] < (int)c.size()){
        if(tmp == 'A'){
            if(a[l[0]] == 'a') tmp = 'A';
            if(a[l[0]] == 'b') tmp = 'B';
            if(a[l[0]] == 'c') tmp = 'C';
            l[0]++;
        }
        if(tmp == 'B'){
            if(b[l[1]] == 'a') tmp = 'A';
            if(b[l[1]] == 'b') tmp = 'B';
            if(b[l[1]] == 'c') tmp = 'C';
            l[1]++;
        }
        if(tmp == 'C'){
            if(c[l[2]] == 'a') tmp = 'A';
            if(c[l[2]] == 'b') tmp = 'B';
            if(c[l[2]] == 'c') tmp = 'C';
            l[2]++;
        }
    }
    cout << tmp << endl;
}