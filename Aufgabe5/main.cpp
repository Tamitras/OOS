
#include <iostream>
using namespace std;

// hier die Klasse Punkt implementieren

/// @brief Klasse Point
class Point
{
    /// @brief Private
private:
    int x;
    int y;

    /// @brief Public Getter und Setter
public:
    // Setzt den Wert von x
    void set_x(int x_)
    {
        x = x_;
    }
    // setzt den Wert von y
    void set_y(int y_)
    {
        y = y_;
    }

    // Gibt den Wert von x zurück
    int get_x()
    {
        return x;
    }

    // Gibt den Wert von y zurück
    int get_y()
    {
        return y;
    }

    // Gibt den Wert von x und y aus
    void print()
    {
        cout << "print-Methode:" << endl;
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
    }
};

int main(int argc, char *argv[])
{
    Point p;
    p.set_x(1);
    p.set_y(10);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}
