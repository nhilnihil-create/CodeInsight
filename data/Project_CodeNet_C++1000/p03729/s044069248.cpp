#include<iostream>
#include<string>

using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    int numa = a.size() - 1;
    int numb = b.size() - 1;
    int numc = c.size() - 1;
    if (a[numa] == b[0] && b[numb] == c[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
}
