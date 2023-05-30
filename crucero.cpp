#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
using namespace std;

// Función para mostrar la lista de habitaciones
void mostrarHabitaciones(const set<int> &habitacionesVendidas)
{
    cout << "---------------------------------" << endl;
    cout << "|       Lista de Habitaciones    |" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 1; i <= 100; i++)
    {
        if (i % 10 == 1)
        {
            cout << "| ";
        }

        // Verificar si la habitación está vendida
        if (habitacionesVendidas.count(i) > 0)
        {
            cout << "   "
                 << " "; // Mostrar espacio en blanco si está vendida
        }
        else
        {
            cout << setw(3) << i << " "; // Mostrar número de habitación
        }

        if (i % 10 == 0)
        {
            cout << "|" << endl;
        }
    }

    cout << "---------------------------------" << endl;
}

int main()
{
    string nombre;
    int edad;
    string respuesta;
    int num_pasaje;
    int num_habitaciones;
    set<int> habitacionesVendidas; // Conjunto para almacenar las habitaciones vendidas (sin duplicados)
    double dni;

    // Leer las habitaciones vendidas del archivo (si existe)
    ifstream file("habitaciones_vendidas.txt");
    int habitacion;
    while (file >> habitacion)
    {
        habitacionesVendidas.insert(habitacion);
    }
    file.close();

    cout << "Welcome to Melendez Crucero's" << endl;
    mostrarHabitaciones(habitacionesVendidas); // Mostrar la lista de habitaciones inicial

    cout << "Please enter your name: ";
    getline(cin, nombre);

    cout << "Hello " << nombre << ", please enter your age: " ;
    cin >> edad;

    if (edad > 18)
    {
        cout << "Do you like to buy a ticket for the cruise? (Yes/No): ";
        cin >> respuesta;

        if (respuesta == "Yes" || respuesta == "yes")
        {
            cout << "How many tickets would you like to buy? ";
            cin >> num_pasaje;
        }
    }
    else
    {
        cout << "You are not the minimum age to be part of the cruise. Sorry and have a nice day." << endl;
        return 0; // Finalizar el programa si no cumple con la edad mínima
    }

    cout << "Please enter the number of rooms you would like to purchase: ";
    cin >> num_habitaciones;

    int i = 1;
    while (i <= num_habitaciones)
    {
        int habitacion;
        cout << "Please enter the room number for room " << i << ": ";
        cin >> habitacion;

        // Verificar si la habitación ya ha sido vendida
        if (habitacionesVendidas.count(habitacion) > 0)
        {
            cout << "That room has already been sold. Please choose a different room." << endl;
            continue;
        }

        habitacionesVendidas.insert(habitacion); // Agregar la habitación al conjunto de habitaciones vendidas
        i++;
    }

    // Guardar las habitaciones vendidas en el archivo
    ofstream outfile("habitaciones_vendidas.txt");
    for (int habitacion : habitacionesVendidas)
    {
        outfile << habitacion << endl;
    }
    outfile.close();

    cout << "Please enter your DNI: ";
    cin >> dni;

    cout << "Well " << nombre << ", you bought " << num_pasaje << " ticket(s) and selected " << num_habitaciones << " room(s)." << endl;
    cout << "Thank you for your purchase! Enjoy your cruise." << endl;

    return 0;
}
