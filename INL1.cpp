// INL1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <locale>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 25;
double m�tv�rden[MAX];
int antal = 0;

// Funktion f�r att mata in m�tv�rden
void MeasureInValues() {
    double input;
    cout << "Mata in m�tv�rden (avsluta med 'f'):\n";
    while (antal < MAX) {
        cout << "M�tv�rde " << (antal + 1) << ": ";
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            char c;
            cin >> c;
            if (c == 'f' || c == 'F') break;
            cout << "Felaktig inmatning, f�rs�k igen.\n";
            continue;
        }
        m�tv�rden[antal++] = input;
    }
}

// Funktion f�r att visa statistik
void showStatistics() {
    if (antal == 0) {
        cout << "Inga m�tv�rden att analysera.\n";
        return;
    }

    double summa = 0.0;
    double min = m�tv�rden[0];
    double max = m�tv�rden[0];

    for (int i = 0; i < antal; i++) {
        summa += m�tv�rden[i];
        if (m�tv�rden[i] < min) min = m�tv�rden[i];
        if (m�tv�rden[i] > max) max = m�tv�rden[i];
    }

    double medelv�rde = summa / antal;
    double varians = 0.0;
    for (int i = 0; i < antal; i++) {
        varians += pow(m�tv�rden[i] - medelv�rde, 2);
    }
    varians /= antal;
    double standardavvikelse = sqrt(varians);

    cout << "\n--- Statistik ---\n";
    cout << "Antal v�rden: " << antal << "\n";
    cout << "Summa: " << summa << "\n";
    cout << "Medelv�rde: " << medelv�rde << "\n";
    cout << "Min-v�rde: " << min << "\n";
    cout << "Max-v�rde: " << max << "\n";
    cout << "Varians: " << varians << "\n";
    cout << "Standardavvikelse: " << standardavvikelse << "\n";
}

// Funktion f�r att sortera m�tv�rden
void sortValues() {
    if (antal == 0) {
        cout << "Ingen data att sortera.\n";
        return;
    }
    //skapa en lista h�r
    for (int i = 0; i < antal - 1; i++) {
        for (int j = i + 1; j < antal; j++) {
            if (m�tv�rden[i] > m�tv�rden[j]) {
                double temp = m�tv�rden[i];
                m�tv�rden[i] = m�tv�rden[j];
                m�tv�rden[j] = temp;
            }
        }
    }
    //l�gg till i den nya listan
    for (int i = 0; i < antal; i++) {
        cout << m�tv�rden[i] << " \n";
	}

	//loopa igenom den nya listan och skriv ut v�rdena
    cout << "M�tv�rden sorterade.\n";
}

// Funktion f�r att s�ka efter ett v�rde
void searchValue() {
    if (antal == 0) {
        cout << "Listan �r tom.\n";
        return;
    }
    double s�kt;
    cout << "Ange v�rde att s�ka efter: ";
    cin >> s�kt;
    bool hittad = false;
    for (int i = 0; i < antal; i++) {
        if (m�tv�rden[i] == s�kt) { 
            cout << "V�rdet " << s�kt << " hittades p� position " << (i + 1) << ".\n";
            hittad = true;
        }
    }
    if (!hittad) {
        cout << "V�rdet hittades inte.\n";
    }
}
// Extra utmaningar: Funktion f�r att Sensor simulering.
void simulateSensor() {
    if (antal >= MAX) {
        cout << "Max antal m�tv�rden har redan n�tts.\n";
        return;
    }

    int antalSimuleringar;
    cout << "Hur m�nga m�tv�rden vill du simulera?\n";
    cin >> antalSimuleringar;

    if (antalSimuleringar <= 0 || antalSimuleringar > (MAX - antal)) {
        cout << "Ogiltigt antal. Max tillg�ngliga platser: " << (MAX - antal) << "\n";
        return;
    }

    srand(static_cast<unsigned int>(time(nullptr))); // Initiera slumpgenerator, s� att v�rdena som produceras av rand() �r olika varje g�ng programmet k�rs.

    for (int i = 0; i < antalSimuleringar; i++) {
        double slumpv�rde = 20.0 + static_cast<double>(rand()) / RAND_MAX * 10.0; // 20�30 �C
        m�tv�rden [antal++] = slumpv�rde;
        cout << "Simulerat v�rde " << (antal) << ": " << slumpv�rde << " �C\n";
    }

    cout << "Sensorv�rden har genererats och lagrats.\n";
}

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "SV_se");
    cout << "Hej! V�lkommen till mitt inl�mningsuppgift.\n";

	MeasureInValues();

    int val;
    do {
        cout << "\n--- MENY ---\n";
        cout << "1. L�gg till nya m�tv�rden\n";
        cout << "2. Visa statistiken\n";
        cout << "3. Sortera m�tv�rden\n";
        cout << "4. S�k efter ett visst v�rde\n";
        cout << "5. Simulera sensorv�rden\n";
        cout << "6. Avsluta\n";
        cout << "Ditt val: ";
        cin >> val;

        switch (val) {
		case 1: MeasureInValues(); 
            break;
		case 2: showStatistics(); 
            break;
		case 3: sortValues(); 
            break;
        case 4: searchValue(); 
			break;
        case 5: simulateSensor();
            break;
        case 6: cout << "Avslutar programmet.\n"; 
            break;
        }
    } while (val != 6 && antal < MAX);

    if (antal == MAX) {
        cout << "Max antal m�tv�rden n�tt, avslutar programmet.\n";
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
