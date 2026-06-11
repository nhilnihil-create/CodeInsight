#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i=0;i<N;i++) {
        cin >> a.at(i);
    }
    int button =1;
    bool judge = false;
    int count =0;
    
    for (int i=0;i<N;i++) {
        button = a.at(button-1);
        count++;
        if(button==2) {
            cout << count << endl;
            judge = true;
            break;
        }
        
    }
    if(judge == false) {
        cout << -1 << endl;
    }
    
    
   }

 