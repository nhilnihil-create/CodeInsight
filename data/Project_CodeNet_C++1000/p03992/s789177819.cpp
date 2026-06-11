#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(void){
    int j=0;
    char out[13];
    string str;

    cin >> str;

    for(int i=0;i<str.size();i++){
        out[j]=str[i];
        if(i==3){
            j++;
            out[j]=' ';
        }
        j++;
    }
    cout << out << endl;

    return 0;
}