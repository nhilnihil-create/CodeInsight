#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    for(int i = 0; i < n; i++){
        string current = s.substr(0, n - i - 1);
        //cout << current << endl;
        int newsize = current.size();
        if(newsize%2 == 0){
            int mid = newsize/2;
            string first = current.substr(0, mid);
            string last = current.substr(mid);
            if(first == last){
                //cout << first << " " << last << endl;
                cout << current.size() << endl;
                return 0;
            }
            
        }
    }
    
}
