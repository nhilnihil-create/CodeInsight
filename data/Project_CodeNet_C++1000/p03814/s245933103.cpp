#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s ;
    int begin_number,end_number;
    bool finished =true;
    int size = s.size();
    for(int i=0;i<size;i++){
        if(s[i] == 'A'){
            begin_number= i;
            for(int j=begin_number;j<size;j++){
                if(s[j]=='Z'){
                    end_number= j;
                    
                }

            }
            if(finished){
            break;
            }
        }
        
    }
    int length = (end_number - begin_number + 1);
    cout << length << endl;
}