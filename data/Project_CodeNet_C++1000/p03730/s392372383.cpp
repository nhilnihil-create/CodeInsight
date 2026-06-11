#include<iostream>
#include<string>

using namespace std;

int main(){
    int a, b, c;
    string s = "NO";
    cin >> a >> b >> c;

    for(int i = 1; i < b; i++){
        if(a*i % b == c){
            s = "YES";
            break;
        }
    }

    cout << s << endl;
}