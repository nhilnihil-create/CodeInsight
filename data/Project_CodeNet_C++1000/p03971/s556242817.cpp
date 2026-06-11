#include<bits/stdc++.h>
using namespace std;

int n, a, b;
string s;

int main(void){
    cin >> n >> a >> b;
    cin >> s;
    int sum = 0;
    int rank = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' && sum < a+b){
            cout << "Yes" << endl;
            sum++;
        }else if(s[i] == 'b' && sum < a+b && rank <= b){
            cout << "Yes" << endl;
            sum++;
            rank++;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
