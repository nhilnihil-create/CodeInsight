#include <iostream>
using namespace std;
bool f(int x, int b){
    if(x-2 <= b && b <= x+1)return true;
    if(x == 2 && b == x+2) return true;
    return false;
}
int main() {
    int n, x, b = 1;
    cin >> n >> x;
    if(x == 1 || x == n*2-1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i=1;i<=n*2-1;i++){
        int a;
        if(n-1 <= i && i <= n+2){
            if(i <= n+1){
                if(x == 2)a = x - i + n;
                else      a = x + i - n;
            }else{
                if(x == 2)a = x+2;
                else      a = x-2;
            }
        }else{
            while(f(x, b))b++;
            a = b++;
        }
        cout << a << endl;
    }
	return 0;
}