#include <bits/stdc++.h>
using namespace std;

int main() {
    int count_five = 0;
    int count_seven = 0;
    int n = 3;

    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        if(m != 5 && m != 7){
            cout << "NO" << endl;
            return 0;
        }else{
            switch (m)
            {
            case 5:
                count_five = count_five + 1;
                break;
            case 7:
                count_seven = count_seven + 1;
                break;
            }
            if(2 <= count_seven){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}