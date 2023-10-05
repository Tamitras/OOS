
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{
    string name = "";
    cout << "Name des Spielers: Der Computer hat seine Wahl getroffen." << endl;

    // Kein return wert sondern eine Referenz auf den String
    getline(cin, name);
    return name;
}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        // Die Funktion srand() initialisiert den Zufallsgenerator mit einem Startwert.
        // Der Startwert muss größer als 0 sein.

        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // Die Funktion time() liefert die aktuelle Zeit in Sekunden seit dem 1. Januar 1970 zurück.
        // Das heißt, sie liefert bei jedem Aufruf einen anderen Wert zurück.
        // time liefert aber keinen int sondern den typ time_t zurück.
        // time_t ist ein typedef für einen long.

        // Wie funktioniert die funktion rand?
        // Die Funktion rand() liefert eine zufällige Zahl zurück.

        // Warum wird hier modulo 3 verwendet?
        // Der Modulo-Operator % liefert den Rest einer Division zurück.
        // Beispiel: 5 % 3 = 2, da 5 / 3 = 1 Rest 2. --> DRAW
        // Anderes Beispiel 6 % 3 = 0, da 6 / 3 = 2 Rest 0. --> PLAYER_ONE_WINS

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{
    switch (object)
    {
    case Object::ROCK:
        return "Stein";
    case Object::SCISSORS:
        return "Schere";
    case Object::PAPER:
        return "Papier";

    default:
        return "Ungültige Wahl";
    }

    // HIER programmieren:
    // Abhängig vom vorliegenden Object einen entsprechenden String zurückgeben.
    // z.B: Wenn Object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{
    string choice = get_name(player.choice);
    cout << player.name << " hat das Objekt " << choice << " gewählt" << endl;

    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Object sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Object Schere gewählt"
}

// Die Wahl des Spielers abfragen
Object choose()
{
    int choice = 0;
    bool valid = false;
    cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";

    do
    {
        // choice einlesen
        cin >> choice;

        valid = choice == 1 || choice == 2 || choice == 3;
        // wiederhole also solange die Eingabe nicht einer der drei Möglichkeiten entspricht

    } while (!valid);

    // HIER programmieren:
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    // Stellen sie sicher, dass es sich um eine gültige Wahl handel
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"

    Object ret;

    switch (choice)
    {
    case 1:
        ret = Object::ROCK;
        break;
    case 2:
        ret = Object::SCISSORS;
        break;
    case 3:
        ret = Object::PAPER;
        break;
    }
    return ret;
}

Result determine_result(Player player_1, Player player_2)
{
    // Spieler 1 und 2 haben gleich gewählt
    if (player_1.choice == player_2.choice)
    {
        return Result::DRAW;
    }
    else if ((player_1.choice == Object::ROCK && player_2.choice == Object::SCISSORS) ||
             (player_1.choice == Object::PAPER && player_2.choice == Object::ROCK) ||
             (player_1.choice == Object::SCISSORS && player_2.choice == Object::PAPER))
    {
        // Spieler 1 gewinnt
        return Result::PLAYER_ONE_WINS;
    }
    else
    {
        // Spieler 2 gewinnt
        return Result::PLAYER_TWO_WINS;
    }

    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"
}

void print_result(Player player_1, Player player_2)
{
    Result result = determine_result(player_1, player_2);

    if (result == Result::DRAW)
    {
        cout << "Unentschieden" << endl;
    }
    else if (result == Result::PLAYER_ONE_WINS)
    {
        cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
    }
    else if (result == Result::PLAYER_TWO_WINS)
    {
        cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
    }
    else
    {
        cout << "Ungültiges Ergebnis" << endl;
    }

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"
}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    player_2.choice = choose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}
