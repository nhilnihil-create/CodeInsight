#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    string keys;
    cin>>keys;

    int c = 0;
    vector<int> s;
    for(int i=0; i<keys.length(); i++) {
        if(keys[i] == '0'){
            s.push_back(0);
            c++;
        }
        else if(keys[i] == '1'){
            s.push_back(1);
            c++;
        }
        else if(s.size() > 0){
            s.pop_back();
            c--;
        }
    }

    for(int i=0; i<c; i++){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}