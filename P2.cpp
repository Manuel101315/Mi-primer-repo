//realice un programa quepermita al usuario ingresar tres numeros y diga vuales son los divisores en comun

#include <iostream>
using namespace std;

int main(){
	int a , b , c;
	
	cout <<"ingresa tres numeros:" ;
	cin >> a >> b >> c;
	
	cout <<"los divisores en comun son:";
	
	for (int i= 1; i<= a && i <= b && i <= c; i++){
		if (a % i == 0 &&  	b % i == 0 && c % i == 0){
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;	
}
