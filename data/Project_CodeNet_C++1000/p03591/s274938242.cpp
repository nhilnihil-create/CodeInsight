#include<iostream>
#include<string>

using namespace std;

int main(){
	string s, s2 = "YAKI";
	cin >> s;
    if(s.size() < 4){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < 4; i++){
        if(s[i] != s2[i]){
            cout << "No" << endl;
            return 0;
        }
    }
	cout << "Yes" << endl;
	return 0;
}
