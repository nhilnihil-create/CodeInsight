#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

void cout_vec(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    string S, T;
    cin >> S >> T;

    vector<int> accS((int)S.size()+1, 0);
    vector<int> accT((int)T.size()+1, 0);
    for(int i=0; i<(int) accS.size()-1; i++){
        if(S[i]=='B'){
            accS[i+1]=accS[i]+2;
        }else{
            accS[i+1]=accS[i]+1;
        }
    }
    for(int i=0; i<(int) accT.size()-1; i++){
        if(T[i]=='B'){
            accT[i+1]=accT[i]+2;
        }else{
            accT[i+1]=accT[i]+1;
        }
    }

    //cout_vec(accS);
    //cout_vec(accT);

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;

        if((accS[b]-accS[a])%3==(accT[d]-accT[c])%3){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}