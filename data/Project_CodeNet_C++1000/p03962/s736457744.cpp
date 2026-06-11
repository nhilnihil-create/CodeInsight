#include<iostream>
using namespace std;

int a,b,c;

int main(){
	cin>>a>>b>>c;

while(a==b && b==c){
	cout<<"1"<<endl;
	break;
}
while((a==b&&b!=c)||(b==c&&c!=a)||(c==a&&a!=b)){
	cout<<"2"<<endl;
	break;
}
while(a!=b && b!=c&&c!=a){
	 cout<<"3"<<endl;
	 break;

} 

return 0;
}