#include <iostream>
#include <set>
using namespace std;

int main() {
    string data;
    cin>>data;
    set<char> r;
    for(int i=0;i<data.length();i++)
    r.insert(data[i]);
    bool check= false;
    for(char i='a';i<='z';i++)
    if(!r.count(i))
    {
        cout<<i<<endl;
        check=true;
        break;
    }
    if(!check)
        cout<<"None"<<endl;
}