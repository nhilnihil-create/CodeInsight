#include<bits/stdc++.h>
using  namespace  std;
int main() {

    string str;
    cin>>str;

    sort(str.begin(),str.end());

    int count = 1;
    bool flag = true;
    for(int i=0;i<str.size()-2 && flag;i++){

        if(str[i]==str[i+1]){
            count++;
            continue;
        }
        if(count%2==0){
            count=1;

        }
        else{
            flag = false;
        }
    }

    if(flag){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


    return 0;
}