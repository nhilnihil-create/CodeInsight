#include<bits/stdc++.h>

using namespace std;

int main() {
    string w;
    cin>>w;
    int len = w.length();
    int a[26] = {0};
    int flag = 0;
    for(int i = 0; i < len; i++) {
        a[w[i]-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(a[i]%2 == 1){
            flag = 1;
            break;
        }
    }
    if(!flag) {
        cout<<"Yes"<<endl;
    }else {
        cout<<"No"<<endl;
    }
    return 0;
}