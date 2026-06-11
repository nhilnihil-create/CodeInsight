#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    string s;
    cin >> s;
    vector<int> h(4);
    for(int i=0;i<s.size();i++){
        if(s.at(i)=='N')h.at(0)++;
        else if(s.at(i)=='W')h.at(1)++;
        else if(s.at(i)=='S')h.at(2)++;
        else if(s.at(i)=='E')h.at(3)++;
    }
    if(((h.at(0)>0&&h.at(2)>0)||(h.at(0)==0&&h.at(2)==0))&&((h.at(1)>0&&h.at(3)>0)||(h.at(1)==0&&h.at(3)==0)))cout << "Yes" <<endl;
    else cout << "No" << endl;

    return 0;
}
