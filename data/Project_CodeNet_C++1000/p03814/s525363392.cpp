#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int min=-1,max=0;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A' && min == -1){
            min = i;
        }

        if(s[i]=='Z'){
            if(max<i){
                max = i;
            }
        }
    }

    cout << max - min +1 << endl; 
}

