#include <iostream>
#include <string>

using namespace std;

enum color {verde, amarillo, naranja, rojo};
enum comparacion{menorque,mayorque,igualque};

struct pimiento{
    string nombre;
    int shu;
    color Color;
};

typedef pimiento T;

struct Nodo{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *Arbol;

//Creando el arbol
Arbol crearArbol(T x);

//Funciones del pimiento
pimiento solicitarDato();
void mostrarPimiento(pimiento unPimiento);
void mostrarRojo(pimiento unPimiento);
void mostrarSHU(pimiento unPimiento);
bool comparar(pimiento a, comparacion operador, pimiento b);

//Agregar los nodos
void asignarIzq(Arbol a, T unDato);
void asignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);

//Recorriendo el arbol
void preorden(Arbol a);
void inorden(Arbol a);
void postorden(Arbol a);
void RInOrden(Arbol a);
void RPosOrden(Arbol a);
void RPreOrden(Arbol a);

int main(){
    cout << endl;
    cout<<"Iniciando la creacion del arbol..." << endl;
    cout << endl << "Ingrese los datos del pimiento a contener en la raiz: " << endl;
    Arbol arbol = crearArbol(solicitarDato());
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << endl << "---MENU PIMIENTO---" << endl;
        cout << "1) Agregar" << endl;
        cout << "2) Recorrer IN orden (Todos)" << endl;
        cout << "3) Recorrer PRE orden (Rojos)" << endl;
        cout << "4) Recorrer POST orden (Mas picantes)" << endl;
        cout << "5) Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion; cin.ignore();

        switch(opcion){
            case 1: 
                agregarNodo(arbol); 
                break;
            case 2: 
                RInOrden(arbol); 
                break;
            case 3:
                RPreOrden(arbol); 
                break;
            case 4: 
                RPosOrden(arbol); 
                break;
            case 5: 
                cout << endl << "Saliendo..." << endl;
                continuar = false; 
                break;
            default: 
                cout << "Opcion incorrecta!" << endl; 
                break;
        }

    }while(continuar);
    
    return 0;
}

pimiento solicitarDato(){
    pimiento unPimiento;
    int opcion = 0;
    bool continuar = true;

    cout << "Nombre del pimiento: ";
    getline(cin, unPimiento.nombre);

    cout << "SHU del pimiento: ";
    cin >> unPimiento.shu; cin.ignore();
    while(unPimiento.shu < 0){
        cout << endl << "Error: El SHU no puede ser menor que cero" << endl;
        cout << endl <<"SHU del pimiento: ";
        cin >> unPimiento.shu; cin.ignore();
    }

    while(continuar){
        cout << "Elija el color del pimiento: " << endl;
        cout << "1) Verde \t3) Naranja" << endl;
        cout << "2) Amarillo \t4) Rojo" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion; cin.ignore();

        switch(opcion){
            case 1: 
                unPimiento.Color=verde;
                continuar = false;
                break;
            case 2:
                unPimiento.Color=amarillo;
                continuar = false;
                break;
            case 3:
                unPimiento.Color=naranja;
                continuar = false;
                break;
            case 4:
                unPimiento.Color=rojo;
                continuar = false;
                break;
            default:
                cout << endl << "Opcion no valida." << endl << endl;
                break;
        }
    }
    return unPimiento;
}

void mostrarPimiento(pimiento unPimiento){
    cout << endl << "Nombre del pimiento: " << unPimiento.nombre << " / ";
    cout << "SHU del pimiento: " << unPimiento.shu << " / ";
    cout << "Color del pimiento: ";
    if(unPimiento.Color == 0){
            cout << "Verde";
        }
        if(unPimiento.Color == 1){
            cout << "Amarillo";
        }
        if(unPimiento.Color == 2){
            cout << "Naranja";
        }
        if(unPimiento.Color == 3){
            cout << "Rojo";
        }
}

void mostrarRojo(pimiento unPimiento){

    if(unPimiento.Color==rojo){
        cout << endl << "Nombre del pimiento: " << unPimiento.nombre << " / ";
        cout << "SHU del pimiento: " << unPimiento.shu << " / ";
        cout << "Color del pimiento: ";
        if(unPimiento.Color == 0){
            cout << "Verde";
        }
        if(unPimiento.Color == 1){
            cout << "Amarillo";
        }
        if(unPimiento.Color == 2){
            cout << "Naranja";
        }
        if(unPimiento.Color == 3){
            cout << "Rojo";
        }
    }
}

void mostrarSHU(pimiento unPimiento){

    if(unPimiento.shu > 50000){
        cout << endl << "Nombre del pimiento: " << unPimiento.nombre << " / ";
        cout << "SHU del pimiento: " << unPimiento.shu << " / ";
        cout << "Color del pimiento: ";
        if(unPimiento.Color == 0){
            cout << "Verde";
        }
        if(unPimiento.Color == 1){
            cout << "Amarillo";
        }
        if(unPimiento.Color == 2){
            cout << "Naranja";
        }
        if(unPimiento.Color == 3){
            cout << "Rojo";
        }
    }
}

bool comparar(pimiento a, comparacion operador, pimiento b){
    bool resultado = false;

    switch(operador){
        case menorque: resultado = a.shu < b.shu; break;
        case mayorque: resultado = a.shu > b.shu; break;
        case igualque: resultado = a.shu == b.shu; break;
    }
    return resultado;
}

Arbol crearArbol(T x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

void asignarIzq(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol izquierdo ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol derecho ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    
    cout << endl << "--PIMIENTO A AGREGAR--" << endl;
    T unDato = solicitarDato();
    
    Arbol p = a;
    
    while(true){
        if(comparar(unDato, igualque, p->info)){
            cout << endl << "Error: este pimiento ya existe!" << endl;
            return;
        }
        else if(comparar(unDato, menorque, p->info)){
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }

    if(comparar(unDato, menorque, p->info))
        asignarIzq(p, unDato);
    else
        asignarDer(p, unDato);
}

void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        mostrarPimiento(a->info);
        inorden(a->der);
    }
}

void preorden(Arbol a){
    if(a != NULL){
        mostrarRojo(a->info);
        preorden(a->izq);
        preorden(a->der);
    }
}

void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        mostrarSHU(a->info);
    }
}

void RInOrden(Arbol a){
    cout << endl << "--IN ORDEN--"; inorden(a); cout << endl;
}

void RPreOrden(Arbol a){
    cout << endl << "--PRE ORDEN--"; preorden(a); cout << endl;
}

void RPosOrden(Arbol a){
    cout << endl << "--POST ORDEN--"; postorden(a); cout << endl;
}