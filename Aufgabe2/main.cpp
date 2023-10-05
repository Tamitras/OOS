
#include <string>
#include <iostream>
using namespace std;

struct ListElement
{
    int id;
    ListElement* p_next;
};

ListElement* p_root = nullptr;

void add_new_head_element(int id)
{
    ListElement* p_new_element = new ListElement();
    p_new_element->id = id;
    p_new_element->p_next = p_root;
    p_root = p_new_element;
}

// Funktion zum Hinzufügen eines neuen Listenelements am Ende der Liste
void add_new_tail_element(int id)
{
    // Ein neues Objekt vom Typ ListElement wird erzeugt und der Pointer p_new_element zeigt auf dieses Objekt (new) Speicherplatz auf dem Heap wird reserviert
    ListElement* p_new_element = new ListElement();

    // Setzen der ID für das neue Element
    p_new_element->id = id;

    // Das "next" Attribut des neuen Elements wird auf nullptr gesetzt, da es das letzte Element der Liste ist
    // Neu in C++ ist der nullptr, der den Nullpointer 0 ersetzt
    p_new_element->p_next = nullptr;

    // Überprüfung, ob die Liste leer ist. Dies ist der Fall, wenn p_root == nullptr ist
    if (p_root == nullptr) {
        // Wenn die Liste leer ist, wird das neue Element zum Wurzelelement der Liste
        p_root = p_new_element;

    } else {
        // Ist die Liste nicht leer, durchlaufen wir die Liste bis zum letzten Element
        // Beginnen bei der Wurzel der Liste
        ListElement* p_tmp = p_root;

        // Durchlaufen der Liste solange das aktuelle Element nicht nullptr ist
        while (p_tmp->p_next != nullptr) {
            // Gehe zum nächsten Element in der Liste
            p_tmp = p_tmp->p_next;
        }

        // Anhängen des neuen Elements am Ende der Liste
        p_tmp->p_next = p_new_element;
    }
}

void delete_element(int id)
{
    ListElement *p_tmp = p_root;
    ListElement *p_predecessor = nullptr;

    while (p_tmp != nullptr && p_tmp->id != id)
    {
        p_predecessor = p_tmp;
        p_tmp = p_tmp->p_next;
    }
    if (p_tmp != nullptr)
    {
        if (p_tmp == p_root)
        {
            p_root = p_tmp->p_next;
        }
        else
        {
            p_predecessor->p_next = p_tmp->p_next;
        }
    }
    delete p_tmp;
}

// Gibt die komplette Liste auf der Konsole aus
void print_list()
{
    // Beginnen bei der Wurzel der Liste
    ListElement* p_tmp = p_root;

    // Durchlaufen der Liste solange, bist das aktuelle Element nicht nullptr ist
    while (p_tmp != nullptr) {

        // Ausgabe der ID des aktuellen Objekts auf der Konsole
        cout << p_tmp->id << endl;

        // Gehe zum nächsten Element in der Liste
        p_tmp = p_tmp->p_next;
    }
    // Der Durchlauf endet automatisch, wenn das Ende der Liste erreicht ist (d.h. p_tmp == nullptr)
}

int main(int argc, char* argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};

