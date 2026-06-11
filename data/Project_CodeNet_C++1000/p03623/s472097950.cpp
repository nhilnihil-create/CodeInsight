#include <stdio.h>
int main (){
	int lokasi, a, b, x, y;
	//lokasi rumah, toko a, toko b 
	scanf ("%d %d %d", &lokasi, &a , &b);
	
	x= a- lokasi; 
	y= b- lokasi; 
	if (x<0){
	x=-1*(x);
	}
	if (y<0){
	
	y=-1*(y);
	}
	if (x< y){
	printf ("A");
	}else{
	
	printf ("B");
}
	
	return 0; 
}