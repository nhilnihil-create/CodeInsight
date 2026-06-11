#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    vector<int> count(n,0);
    for(int i = 0; i < m; ++i){
        cin >> a.at(i) >> b.at(i);
        count.at(a.at(i)-1)++;
        count.at(b.at(i)-1)++;
    }
    for(int i=0; i<n; ++i){
        cout << count.at(i) << endl;
    }
}
