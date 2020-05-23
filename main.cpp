#include <windows.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
//#include "Persona.h"
#include "Persona.cpp"
#include <stdlib.h> 
#include <time.h>


using namespace std;

void Enviar_mensaje (Persona* mensajero, Persona* receptor){
	string mensaje ;
	string enviador = mensajero->getNombre();
	cout<<"Escriba que mensaje quiere enviar :"<<endl ;
	//getline(cin,mensaje);
	cin>> mensaje;
	mensaje+="\n ";
	mensaje +=enviador;
	receptor->addMensaje(mensaje);
	cout<< "Mensaje Enviado !"<< endl;
}

int main (){
	int respuesta=0 ;
	
	vector<Persona*>vPersonas;
	
	while (respuesta!=3 ){
		cout<<"1.- Registrarse"<<endl;
		cout<<"2.- Ingresar"<<endl;
		cout<<"3.- Salir "<<endl;
		cin >> respuesta ;
		
		switch (respuesta){
			case 1: {
				int llave;
				string nombre;
				string apellido;
				string contra;
				cout<<"Ingrese su nombre"<<endl;
				cin>> nombre;
				cout<<"Ingrese su apellido"<<endl;
				cin >> apellido;
//				cout<<"Ingrese su llave"<<endl;
//				cin >> llave;
				cout<<"Ingrese su contrasena"<<endl;
				cin >> contra;
				
				srand(time(NULL));
				llave = 1+rand()%(16-1);
				
				Persona* nuevo= NULL; 
				nuevo = new Persona(llave,nombre,contra,apellido);
				
				//nuevo = new Persona();
				//vPersonas.push_back(nuevo); 
				vPersonas.push_back(nuevo);
				
				
				
				break;
			}
			case 2 : {
				string nombre;
				string contra;
				bool login= false;
				
				cout << "Lista de usuarios: "<< vPersonas.size()<<endl;
				cout <<"Ingrese su nombre : "<<endl;
				cin>>nombre;
				cout << "Ingrese su contrasena : "<< endl;
				cin>> contra ;
				Persona* usuario_activo = NULL;
				
			
				for (int i = 0 ; i<=vPersonas.size(); i++){
				//	cout<< "Entre al for";
				//	cout <<  vPersonas[i]->getNombre()<< endl;
					
				//	 cout << vPersonas[i]->getContra();
					if (nombre == vPersonas[i]->getNombre()){
						if (contra== vPersonas[i]->getContra()){
						//	cout<< "entre al if del for";
							login = true;
							usuario_activo= vPersonas[i];
							break;
							
						}
						
					}
				}
				
				if (login == true ){
					cout << "Bienvenido: "<<usuario_activo->getNombre() << endl ;
					int resp_usuario;
					cout<<"1.- Enviar Mensaje"<< endl ;
					cout<<"2.- Ver Mensajes "<< endl ;
					cout <<"3.- Ver mi llave "<< endl ;
					cout <<"0.- Salir"<< endl ;
					cin>>resp_usuario;
					switch(resp_usuario){
						case 1:{
							for (int i = 0 ; i<vPersonas.size(); i++){
								cout << i <<".- " << vPersonas[i]->getNombre()<<endl;
							}
							int recibidor ;
							cin >>recibidor;
							Persona* receptor = vPersonas[recibidor];
							
							Enviar_mensaje(usuario_activo,receptor);
						
							break;
						}
						case 2 :{
//							for (int i =0; usuario_activo->){// aquise supone que se iban a ver los mensajes pero ya no me da tiempo
//								
//							}
							
							break;
						}
						case 3:{
							
							break;
						}
						
					}
					
					
				}				
				
				break;
			}
		}
	}
	return 0;
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
