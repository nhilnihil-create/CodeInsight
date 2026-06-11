#include<iostream>
#include<string>
#include<list>

using namespace std;



int main(){
    int N, L, i=1, j;
    bool flag;
    string input;
    string a;
    list<string> s;
    list<string>::iterator itr;
    
    cin >> N >> L;
    cin >> input;
    s.push_front(input);
    while (i != N){
        cin >> input;
        flag = false;
        for (itr=s.begin(); itr!=s.end(); itr++){
            a = *itr;
            j = 0;
            while (input[j] <= a[j]){
                if (input[j] < a[j] || j == L-1){
                    s.insert(itr, input);
                    flag = true;
                    break;
                }
                j++;
            }
            if (flag == true){
                break;
            }      
        }
        if (flag == false){
            s.push_back(input);
        }
        i++;
    }

    for (itr=s.begin(); itr!=s.end(); itr++){
        cout << *itr;
    }

    return 0;
}