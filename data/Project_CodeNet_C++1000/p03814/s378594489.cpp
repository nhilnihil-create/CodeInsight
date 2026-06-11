#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int zn =0;
    int an =0;
    for(int i = 0;i<s.size();i++){
        if (s[i] == 'Z'){
            zn = i;
        }
    }
    for(int i = s.size();i>=0;i--){
        if (s[i] == 'A'){
            an = i;
        }
    }
    cout<<zn-an+1<<endl;
}