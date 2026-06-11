//http://abc058.contest.atcoder.jp/tasks/abc058_a
#include <iostream>
using namespace std;

int a,b,c;

void read_input(){
    cin >> a >> b >> c;
}

int main(void){
    read_input();
    if (b-a == c-b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}