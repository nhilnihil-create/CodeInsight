#include<iostream>
#include<string>

using namespace std;

int main(){
    string s, s_r;
    cin >> s;
    for (unsigned int i=0; i<s.length(); i++){
            s_r.push_back(s[s.length()-i-1]);
        }
    while(!s_r.empty()){
        if (s_r.substr(0,5) == "maerd"){
            s_r = s_r.erase(0,5);
        }
        else if(s_r.substr(0,7) == "remaerd"){
            s_r = s_r.erase(0,7);
        }
        else if (s_r.substr(0,5) == "esare"){
            s_r = s_r.erase(0,5);
        }
        else if (s_r.substr(0,6) == "resare"){
            s_r = s_r.erase(0,6);
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}