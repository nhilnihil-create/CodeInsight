#include<iostream>
using namespace std;
#include <string>
int main()
{
    // 整数の入力
    int a,b;
    cin >> a >> b;
	int x,y;
	
	int i,j;
	string c("A");
	string s;
	string s1 = "snuke";
	
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			cin >> s;
			if(s=="snuke"){
				x=i;
				y=j;
			}
		}
	}
    // 出力
	c='A'+y;
	x+=1;
    cout << c << x << endl;
    return 0;
}