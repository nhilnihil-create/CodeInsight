#include <iostream>
using namespace std;

int total, banyakanak;

int main (){
	cin>>banyakanak;
	for (int i=banyakanak; i>=0; i--){
		total+=i;
	}
	cout<<total<<endl;
}