// INL1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <locale>
#include <cmath>

using namespace std;

const int MAX = 25;
double mätvärden[MAX];
int antal = 0;

// Funktion för att mata in mätvärden
void MeasureInValues() {
    double input;
    cout << "Mata in mätvärden (avsluta med 'f'):\n";
    while (antal < MAX) {
        cout << "Mätvärde " << (antal + 1) << ": ";
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            char c;
            cin >> c;
            if (c == 'f' || c == 'F') break;
            cout << "Felaktig inmatning, försök igen.\n";
            continue;
        }
        mätvärden[antal++] = input;
    }
}

// Funktion för att visa statistik
void showStatistics() {
    if (antal == 0) {
        cout << "Inga mätvärden att analysera.\n";
        return;
    }

    double summa = 0.0;
    double min = mätvärden[0];
    double max = mätvärden[0];

    for (int i = 0; i < antal; i++) {
        summa += mätvärden[i];
        if (mätvärden[i] < min) min = mätvärden[i];
        if (mätvärden[i] > max) max = mätvärden[i];
    }

    double medelvärde = summa / antal;
    double varians = 0.0;
    for (int i = 0; i < antal; i++) {
        varians += pow(mätvärden[i] - medelvärde, 2);
    }
    varians /= antal;
    double standardavvikelse = sqrt(varians);

    cout << "\n--- Statistik ---\n";
    cout << "Antal värden: " << antal << "\n";
    cout << "Summa: " << summa << "\n";
    cout << "Medelvärde: " << medelvärde << "\n";
    cout << "Min-värde: " << min << "\n";
    cout << "Max-värde: " << max << "\n";
    cout << "Varians: " << varians << "\n";
    cout << "Standardavvikelse: " << standardavvikelse << "\n";
}

// Funktion för att sortera mätvärden
void sortValues() {
    if (antal == 0) {
        cout << "Ingen data att sortera.\n";
        return;
    }
    //skapa en lista här
    for (int i = 0; i < antal - 1; i++) {
        for (int j = i + 1; j < antal; j++) {
            if (mätvärden[i] > mätvärden[j]) {
                double temp = mätvärden[i];
                mätvärden[i] = mätvärden[j];
                mätvärden[j] = temp;
            }
        }
    }
    //lägg till i den nya listan
    for (int i = 0; i < antal; i++) {
        cout << mätvärden[i] << " \n";
	}

	//loopa igenom den nya listan och skriv ut värdena
    cout << "Mätvärden sorterade.\n";
}

// Funktion för att söka efter ett värde
void searchValue() {
    if (antal == 0) {
        cout << "Listan är tom.\n";
        return;
    }
    double sökt;
    cout << "Ange värde att söka efter: ";
    cin >> sökt;
    bool hittad = false;
    for (int i = 0; i < antal; i++) {
        if (mätvärden[i] == sökt) {
            cout << "Värdet " << sökt << " hittades på position " << (i + 1) << ".\n";
            hittad = true;
        }
    }
    if (!hittad) {
        cout << "Värdet hittades inte.\n";
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "SV_se");
    cout << "Hej världen!\n";

	MeasureInValues();

    int val;
    do {
        cout << "\n--- MENY ---\n";
        cout << "1. Lägg till nya mätvärden\n";
        cout << "2. Visa statistiken\n";
        cout << "3. Sortera mätvärden\n";
        cout << "4. Sök efter ett visst värde\n";
        cout << "5. Avsluta\n";
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
        case 5: cout << "Avslutar programmet.\n"; 
            break;
        }
    } while (val != 5 && antal < MAX);

    if (antal == MAX) {
        cout << "Max antal mätvärden nått, avslutar programmet.\n";
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
