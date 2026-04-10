#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Producto {
    int id;
    string nombre;
    float precio;
    int cantidad;
};

vector<Producto> inventario;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int buscarProducto(int id) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].id == id) {
            return i;
        }
    }
    return -1;
}

void agregarProducto() {
    Producto p;

    cout << "\nIngrese ID del producto: ";
    cin >> p.id;

    if (cin.fail() || p.id <= 0) {
        cout << "ID invalido.\n";
        limpiarBuffer();
        return;
    }

    if (buscarProducto(p.id) != -1) {
        cout << "El ID ya existe.\n";
        return;
    }

    cout << "Ingrese nombre del producto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p.nombre);

    if (p.nombre.empty()) {
        cout << "Nombre no puede estar vacio.\n";
        return;
    }

    cout << "Ingrese precio: ";
    cin >> p.precio;

    if (cin.fail() || p.precio <= 0) {
        cout << "Precio invalido.\n";
        limpiarBuffer();
        return;
    }

    cout << "Ingrese cantidad: ";
    cin >> p.cantidad;

    if (cin.fail() || p.cantidad < 0) {
        cout << "Cantidad invalida.\n";
        limpiarBuffer();
        return;
    }

    inventario.push_back(p);
    cout << "Producto agregado correctamente.\n";
}

void eliminarProducto() {
    int id;
    cout << "\nIngrese ID a eliminar: ";
    cin >> id;

    if (cin.fail()) {
        cout << "ID invalido.\n";
        limpiarBuffer();
        return;
    }

    int index = buscarProducto(id);

    if (index == -1) {
        cout << "Producto no encontrado.\n";
        return;
    }

    inventario.erase(inventario.begin() + index);
    cout << "Producto eliminado.\n";
}

void mostrarProducto() {
    int id;
    cout << "\nIngrese ID a buscar: ";
    cin >> id;

    if (cin.fail()) {
        cout << "ID invalido.\n";
        limpiarBuffer();
        return;
    }

    int index = buscarProducto(id);

    if (index == -1) {
        cout << "Producto no encontrado.\n";
        return;
    }

    Producto p = inventario[index];

    cout << "\nProducto encontrado:\n";
    cout << "ID: " << p.id << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Precio: " << p.precio << endl;
    cout << "Cantidad: " << p.cantidad << endl;
}

void actualizarProducto() {
    int id;
    cout << "\nIngrese ID a actualizar: ";
    cin >> id;

    if (cin.fail()) {
        cout << "ID invalido.\n";
        limpiarBuffer();
        return;
    }

    int index = buscarProducto(id);

    if (index == -1) {
        cout << "Producto no encontrado.\n";
        return;
    }

    Producto &p = inventario[index];

    cout << "Nuevo nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p.nombre);

    cout << "Nuevo precio: ";
    cin >> p.precio;

    if (cin.fail() || p.precio <= 0) {
        cout << "Precio invalido.\n";
        limpiarBuffer();
        return;
    }

    cout << "Nueva cantidad: ";
    cin >> p.cantidad;

    if (cin.fail() || p.cantidad < 0) {
        cout << "Cantidad invalida.\n";
        limpiarBuffer();
        return;
    }

    cout << "Producto actualizado.\n";
}

void mostrarInventario() {
    if (inventario.empty()) {
        cout << "\nInventario vacio.\n";
        return;
    }

    cout << "\nInventario:\n";
    for (int i = 0; i < inventario.size(); i++) {
        Producto p = inventario[i];
        cout << "-------------------\n";
        cout << "ID: " << p.id << endl;
        cout << "Nombre: " << p.nombre << endl;
        cout << "Precio: " << p.precio << endl;
        cout << "Cantidad: " << p.cantidad << endl;
    }
}

void menu() {
    int opcion;

    do {
        cout << "\n===== PAPELERIA =====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Buscar producto\n";
        cout << "4. Actualizar producto\n";
        cout << "5. Mostrar inventario\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Opcion invalida.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: eliminarProducto(); break;
            case 3: mostrarProducto(); break;
            case 4: actualizarProducto(); break;
            case 5: mostrarInventario(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n";
        }

    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}

