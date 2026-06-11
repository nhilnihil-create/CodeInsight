#include <iostream>
#include <string>
using namespace std;

int pnjgeven, pnjgodd, total, itungeven, itungodd;
string odd, even, akhir;

int main (){
	cin>>odd>>even;
	pnjgodd=odd.length();
	pnjgeven=even.length();
	total=pnjgodd+pnjgeven;
	for (int i=0; i<=total-1; i++){
		if (i%2==0){
			akhir+=odd [itungodd];
			itungodd++;
		}else {
			akhir+=even [itungeven];
			itungeven++;
		}
	}
	cout<<akhir<<endl;
}