#include <string>
#include <iostream>
using namespace std;

// Anmerkung:
// In dieser Datei verwenden wir das Schlüsselwort "const" bei Methoden. 
// Ein "const" nach der Methodendeklaration bedeutet, dass diese Methode den Zustand des Objekts 
// nicht ändert und auf konstanten Objekten aufgerufen werden kann.

// Klasse Student repräsentiert einen Studenten mit Name und Vorname.
class Student {
private:
    string _name;       // Nachname des Studenten
    string _first_name; // Vorname des Studenten

public:
    // Konstruktor, der den vollen Namen des Studenten initialisiert.
    Student(string name, string first_name);

    // Destruktor, gibt eine Nachricht aus, wenn ein Studentenobjekt zerstört wird.
    ~Student();

    // Getter-Methode für den Nachnamen.
    string get_name() const;

    // Getter-Methode für den Vornamen.
    string get_first_name() const;

    // Methode zum Ausdrucken des vollen Namens des Studenten (mit Zeilenumbruch).
    void print() const;

    // Überladene Methode zum Ausdrucken des vollen Namens. 
    // Kann gesteuert werden, ob ein Zeilenumbruch am Ende hinzugefügt wird.
    void print(bool line_break) const;
};

Student::Student(string name, string first_name) : _name(name), _first_name(first_name) {
    cout << "Parametrisierter Konstruktor Student: " << _first_name << " " << _name << endl;
}

Student::~Student() {
    cout << "Destruktor Student: " << _first_name << " " << _name << endl;
}

string Student::get_name() const {
    return _name;
}

string Student::get_first_name() const {
    return _first_name;
}

void Student::print() const {
    cout << "print() ohne Parameter; Student: " << _first_name << " " << _name << endl;
}

void Student::print(bool line_break) const {
    cout << "print() mit Parameter; Student: " << _first_name << " " << _name;
    if (line_break) cout << endl;
}

// Klasse Employee repräsentiert einen Mitarbeiter mit Name und Vorname.
class Employee {
private:
    string _name;       // Nachname des Mitarbeiters
    string _first_name; // Vorname des Mitarbeiters

public:
    // Standardkonstruktor, der einen Mitarbeiter mit Standardnamen "Erika Mustermann" erstellt.
    Employee();

    // Konstruktor, der den vollen Namen des Mitarbeiters initialisiert.
    Employee(string name, string first_name);

    // Konvertierkonstruktor, der ein Studentenobjekt nimmt und einen Mitarbeiter daraus erstellt.
    Employee(const Student& stud);

    // Destruktor, gibt eine Nachricht aus, wenn ein Mitarbeiterobjekt zerstört wird.
    ~Employee();

    // Methode zum Ausdrucken des vollen Namens des Mitarbeiters (mit Zeilenumbruch).
    void print() const;

    // Überladene Methode zum Ausdrucken des vollen Namens. 
    // Kann gesteuert werden, ob ein Zeilenumbruch am Ende hinzugefügt wird.
    void print(bool line_break) const;
};

Employee::Employee() : Employee("Mustermann", "Erika") {
    cout << "Standardkonstruktor Employee: Erika Mustermann" << endl;
}

Employee::Employee(string name, string first_name) : _name(name), _first_name(first_name) {
    cout << "Parametrisierter Konstruktor Employee: " << _first_name << " " << _name << endl;
}

Employee::Employee(const Student& stud) : _name(stud.get_name()), _first_name(stud.get_first_name()) {
    cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << endl;
}

Employee::~Employee() {
    cout << "Destruktor Employee: " << _first_name << " " << _name << endl;
}

void Employee::print() const {
    cout << "print() ohne Parameter; Mitarbeiter: " << _first_name << " " << _name << endl;
}

void Employee::print(bool line_break) const {
    cout << "print() mit Parameter; Mitarbeiter: " << _first_name << " " << _name;
    if (line_break) cout << endl;
}

int main(int argc, char *argv[]) {
    // Erstellt ein Studentenobjekt mit dem Namen "Max Mustermann".
    Student stud_mustermann = Student("Mustermann", "Max");

    // Erstellt ein Mitarbeiterobjekt aus dem vorherigen Studentenobjekt.
    Employee empl_mustermann = Employee(stud_mustermann);

    // Erstellt ein Mitarbeiterobjekt mit dem Standardnamen "Erika Mustermann".
    Employee mit_default = Employee();

    // Testet die print-Methoden für Studenten und Mitarbeiter.
    stud_mustermann.print();
    stud_mustermann.print(true);
    empl_mustermann.print();
    mit_default.print();
    Student *p_stud_mustermann = nullptr;
    cout << "Block wird betreten" << endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}
