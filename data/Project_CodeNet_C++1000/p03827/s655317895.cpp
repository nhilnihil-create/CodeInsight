#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    int x=0, m=0;
    for(int i=0; i<n; i++){
        if(s.at(i)=='I'){
            x++;
            if(x>m)
                m = x;
        }else if(s.at(i) == 'D')
            x--;
    }

    cout << m << endl;
    return 0;
}