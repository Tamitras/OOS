
#include <iostream>
using namespace std;

/// @brief Deckt folgende aufrufe mit einem parameter ab:
    // function_(1);
    // function_(c);
    // function_(i);
/// @param i_1
/// @return
int function_(int i_1)
{
    cout << "Funktion  1: i_1=" << i_1 << endl;
    return 0;
}

/// @brief Deckt folgende aufrufe mit 2 parametern ab: macht dasselbe wie: int function_(char c_1, int i_1)
// function_(1, 2);
// function_(c, i);
// function_(1.0, 2.0);
// function_(1.0, 1);
// function_(1.0, static_cast<double>(i));
/// @param i_1
/// @param i_2
/// @return
int function_(int i_1, int i_2)
{
    cout << "Funktion  5: i_1=" << i_1 << " i_2=" << i_2 << endl;
    return 1;
}

/// @brief Deckt folgende aufrufe mit zwei parametern ab: macht dasselbe wie: function_(int i_1, int i_2)
// function_(1, 2);
// function_(c, i);
// function_(1.0, 2.0);
// function_(1.0, 1);
// function_(1.0, static_cast<double>(i));
/// @param c_1
/// @param i_1
/// @return
int function_(char c_1, int i_1)
{
    cout << "Funktion  6: c_1=" << c_1 << " i_1=" << i_1 << endl;
    return 1;
}

/// @brief Deckt folgende aufrufe mit 2 oder 3 parametern ab, also alle bis auf die mit einem parameter
///BESONDERES: Rein theoretisch gesehen kann die Funktion für alle aufrufe mit 2 oder 3 parametern verwenden werden,
///funktioniert aber nicht, DA in Zeile 96:    function_(1.0, static_cast<double>(i)); ein static cast auf double verwendet wird. Und double kann nicht als char interpretiert werden.
///function_(1, 2);
///function_(c, i);
///function_(1.0, 2.0);
///function_(1.0, 2.0, 1);
///function_(1.0, 1, 'a');
///function_(1.0, 1);
///function_(1.0, static_cast<double>(i));
///function_(c, c, i);
///function_(c, i);
/// @param d_1 
/// @param i_1 
/// @param c_1 
/// @return 
int function_(double d_1, int i_1, char c_1 = 'a')
{
    cout << "Funktion  8: d_1=" << d_1 << " i_1=" << i_1 << " c_1=" << c_1 << endl;
    return 1;
}

/// @brief Diese Funktion deckt alle fälle ab
/// @param d_1 
/// @param d_2 
/// @param i_1 
/// @return 
int function_(double d_1, double d_2 = 1.1, int i_1 = 0)
{
    cout << "Funktion  9: d_1=" << d_1 << " d_2=" << d_2 << " i_1=" << i_1 << endl;
    return 1;
}

int function_(char c_1, char c_2, int i_1 = 2, char c_3 = 'c')
{
    cout << "Funktion 11: c_1=" << c_1 << " c_2=" << c_2 << " i_1=" << i_1 << " c_3=" << c_3 << endl;
    return 1;
}

int main(int argc, char *argv[])
{
    // function in function_ umbenannt WEIL function bereits in der stdlib definiert ist und es zu komplikationen kommt!!!!
    int i = 1;
    char c = 'a';
    function_(1);
    function_(c);
    function_(i);
    c = function_('a');
    c = 'a';
    function_(1, 2);
    function_(c, i);
    function_(1.0, 2.0);
    function_(1.0, 2.0, 1);
    function_(1.0, 1, 'a');
    function_(1.0, 1);
    function_(1.0, static_cast<double>(i));
    function_(c, c, i);
    function_(c, i);
    return 0;
}
