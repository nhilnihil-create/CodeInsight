#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    string w;
    cin >> w;

    sort(w.begin(), w.end());

    int count=1;
    char target=w[0];
    for(int i=1; i<w.size(); i++){
        char tmp = w[i];
        if(tmp == target){
            count += 1;
        }else{
            if(count%2 == 1){break;}
            target = tmp;
            count =1;
        }
    }

    if(count%2 == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}