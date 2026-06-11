#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string A; 
    cin >>A;
    sort(A.begin(),A.end());
    vector<int>vec(26,0);
    for(int i=0;i<A.size();i++){
        if('a'==A.at(i)){
            vec.at(0)++;
        }

                else if('b'==A.at(i)){
            vec.at(1)++;
        }
                else if('c'==A.at(i)){
            vec.at(2)++;
        }
                else if('d'==A.at(i)){
            vec.at(3)++;
        }
                else if('e'==A.at(i)){
            vec.at(4)++;
        }
                else if('f'==A.at(i)){
            vec.at(5)++;
        }
                else if('g'==A.at(i)){
            vec.at(6)++;
        }
                else if('h'==A.at(i)){
            vec.at(7)++;
        }
                else if('i'==A.at(i)){
            vec.at(8)++;
        }
                else if('j'==A.at(i)){
            vec.at(9)++;
        }
                else if('k'==A.at(i)){
            vec.at(10)++;
        }
                else if('l'==A.at(i)){
            vec.at(11)++;
        }
                else if('m'==A.at(i)){
            vec.at(12)++;
        }        else if('n'==A.at(i)){
            vec.at(13)++;
        }        else if('o'==A.at(i)){
            vec.at(14)++;
        }        else if('p'==A.at(i)){
            vec.at(15)++;
        }        else if('q'==A.at(i)){
            vec.at(16)++;
        }        else if('r'==A.at(i)){
            vec.at(17)++;
        }        else if('s'==A.at(i)){
            vec.at(18)++;
        }        else if('t'==A.at(i)){
            vec.at(19)++;
        }        else if('u'==A.at(i)){
            vec.at(20)++;
        }        else if('v'==A.at(i)){
            vec.at(21)++;
        }        else if('w'==A.at(i)){
            vec.at(22)++;
        }        else if('x'==A.at(i)){
            vec.at(23)++;
        }        else if('y'==A.at(i)){
            vec.at(24)++;
        }        else if('z'==A.at(i)){
            vec.at(25)++;
        }
    }
    for(int i=0;i<26;i++){
        if(vec.at(i)%2==1){
            cout << "No"<<endl;
            return 0;
        }
    }
    cout <<"Yes"<<endl;
}
