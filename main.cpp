#include <iostream> //importar libreria de input y ouput
#include <fstream> //importar libreria para crear, modificar y leer .txt
#include <string> //importar libreria para trabajar con cadenas de texto String

using namespace std; //para no excribir ::std en cada objeto

void registrar(){//define la funcion registrar que no retorna ningun valor 
	string usuario, password; //declara variables tipo string 
	ofstream archivo; //declara un objeto oftream que usara para escribir un archivo
	
	archivo.open("usuarios.txt", ios::app); //abre o crea si no existe el archivo de modo "append"(ios::app) lo q escribe se añadira al final del contenido existente 
	
	if(!archivo){
		cout<<"No se pudo abrir el archivo para escribir" <<endl;
		return;
	} 
	
	cout << "Ingrese un usuario: ";
	cin >> usuario;
	cout <<"Ingrese una contraseña: ";
	cin>>password;
	
	//guarda el usuario y la contraseña
	archivo << usuario << " "<<password<<endl;
	
}

//funcion para iniciar sesion
bool iniciarSesion(){
	string usuario, password, u, p;
	ifstream archivo;
	
	//abre el archivo en modo lectura
	archivo.open("usuarios.txt");
	
	if(!archivo){
		cout << "No se pudo abrir el archivo para leer"<<endl;
		return false;
	}
	
	cout << "Ingrese nombre de usuario: ";
	cin>> usuario;
	cout << "Ingrese contraseña: ";
	cin>> password;
	
	//Verifica si el usuario y la contraseña coinciden con los datos almacenados
	while(archivo >> u >> p){
		if( u == usuario && p == password){
			archivo.close();
			return true;
		}
	}
	archivo.close();
	return false;
}



int main() {
	int opcion;
	cout << "1. Registrar"<<endl;
	cout << "2. Iniciar Sesion" << endl;
	cout << "Seleccione una opcion: ";
	cin >> opcion;
	
	
	if(opcion == 1){
		registrar();
	}else if (opcion == 2){
		if(iniciarSesion()){
			cout << "Inicio de sesion exitoso" <<endl;
		}else{
			cout << "Usuario o contraseña incorrectos" <<endl;
		}
	} else {
		cout << "Opcion no valida" << endl;
	}
	return 0;
}
