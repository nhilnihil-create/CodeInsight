
#include <iostream>
#include <string>

using namespace std;

int main(void){
 string a = "CODEFESTIVAL2016";
 string s;
cin >> s;
int ans = 0;
for( int i = 0; i<16;++i){
 if(a[i] != s[i])ans++;
}
cout << ans<<endl;



}