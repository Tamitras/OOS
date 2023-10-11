#include <iostream>
using namespace std;

// Definition der Funktion print_rectangle mit einem benötigten und einem optionalen Parameter
void print_rectangle(int x, int y = -1)
{
    // Überprüfung, ob der zweite Parameter angegeben wurde
    if (y == -1)
    {
        // Setzen von y auf den Wert von x, falls y nicht angegeben wurde
        y = x; 
    }
    
    // Äußere Schleife, die für die Anzahl der Zeilen des Rechtecks iteriert
    for (int i = 0; i < y; ++i)
    {
        // Innere Schleife, die für die Anzahl der Spalten des Rechtecks iteriert
        for (int j = 0; j < x; ++j)
        {
            // Ausgabe eines "X" mit einem nachfolgenden Leerzeichen für jede Zelle
            cout << "X ";  
        }
        // Erstellen einer neuen Zeile nach dem Füllen einer Zeile mit "X"s
        cout << endl;  
    }

    // Ausgabe einer leeren Zeile nach dem Zeichnen des Rechtecks
    cout << "" << endl;  
}

int main(int argc, char *argv[])
{
    cout << "x = 2, y = 5: " << endl;
    print_rectangle(2, 5);

    cout << "x = 3, y = 3: " << endl;
    print_rectangle(3, 3);

    cout << "x = 4: " << endl;
    print_rectangle(4);

    return 0;
}
