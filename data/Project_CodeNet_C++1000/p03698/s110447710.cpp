#include <iostream>
#include <vector>
using namespace std;


int main(void){
    string s;
    cin >> s;
    vector<int> a(26);
    for(int i = 0;i < s.size();i++){
        a[s[i] - 'a']++;
    }
    for(int i = 0;i < 26;i++){
        if(a[i] > 1){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
     
}
