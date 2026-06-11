#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int> P;
int inf = 100000000;

int main(){
    string s;
    cin >> s;
    int counter = 0;
    char a = s[0];
    for(int i=1;i<s.size();i++){
        char b = s[i];
        if(a != b) counter ++;
        a = b;
    }
    cout << counter << endl;
}