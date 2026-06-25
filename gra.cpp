#include <iostream>
using namespace std;

int main() {
    const int WIERSZE = 6;
    const int KOLUMNY = 7;

    char plansza[WIERSZE][KOLUMNY];
    char gracz = 'X';

    int kolumna;
    int wiersz;
    int licznik;
    int ruchy = 0;

    bool wygrana = false;
    bool poprawnyRuch;

    // Wype³nienie planszy pustymi polami
    for (int i = 0; i < WIERSZE; i++) {
        for (int j = 0; j < KOLUMNY; j++) {
            plansza[i][j] = '.';
        }
    }

    while (wygrana == false && ruchy < WIERSZE * KOLUMNY) {

        // Wyœwietlenie numerów kolumn
        cout << "\n1 2 3 4 5 6 7\n";

        // Wyœwietlenie planszy
        for (int i = 0; i < WIERSZE; i++) {
            for (int j = 0; j < KOLUMNY; j++) {
                cout << plansza[i][j] << " ";
            }
            cout << endl;
        }

        poprawnyRuch = false;

        // Pobieranie ruchu gracza
        while (poprawnyRuch == false) {
            cout << "\nGracz " << gracz
                 << ", wybierz kolumne od 1 do 7: ";

            cin >> kolumna;

            kolumna = kolumna - 1;

            if (kolumna >= 0 && kolumna < KOLUMNY) {

                wiersz = WIERSZE - 1;

                // Szukanie wolnego pola od do³u
                while (wiersz >= 0 &&
                       plansza[wiersz][kolumna] != '.') {
                    wiersz--;
                }

                if (wiersz >= 0) {
                    plansza[wiersz][kolumna] = gracz;
                    poprawnyRuch = true;
                    ruchy++;
                } else {
                    cout << "Ta kolumna jest pelna.\n";
                }

            } else {
                cout << "Nieprawidlowy numer kolumny.\n";
            }
        }

        // Sprawdzenie uk³adu poziomego
        for (int i = 0; i < WIERSZE; i++) {
            for (int j = 0; j <= KOLUMNY - 4; j++) {

                if (plansza[i][j] == gracz &&
                    plansza[i][j + 1] == gracz &&
                    plansza[i][j + 2] == gracz &&
                    plansza[i][j + 3] == gracz) {

                    wygrana = true;
                }
            }
        }

        // Sprawdzenie uk³adu pionowego
        for (int i = 0; i <= WIERSZE - 4; i++) {
            for (int j = 0; j < KOLUMNY; j++) {

                if (plansza[i][j] == gracz &&
                    plansza[i + 1][j] == gracz &&
                    plansza[i + 2][j] == gracz &&
                    plansza[i + 3][j] == gracz) {

                    wygrana = true;
                }
            }
        }

        // Sprawdzenie uk³adu ukoœnego: w dó³ i w prawo
        for (int i = 0; i <= WIERSZE - 4; i++) {
            for (int j = 0; j <= KOLUMNY - 4; j++) {

                if (plansza[i][j] == gracz &&
                    plansza[i + 1][j + 1] == gracz &&
                    plansza[i + 2][j + 2] == gracz &&
                    plansza[i + 3][j + 3] == gracz) {

                    wygrana = true;
                }
            }
        }

        // Sprawdzenie uk³adu ukoœnego: w dó³ i w lewo
        for (int i = 0; i <= WIERSZE - 4; i++) {
            for (int j = 3; j < KOLUMNY; j++) {

                if (plansza[i][j] == gracz &&
                    plansza[i + 1][j - 1] == gracz &&
                    plansza[i + 2][j - 2] == gracz &&
                    plansza[i + 3][j - 3] == gracz) {

                    wygrana = true;
                }
            }
        }

        if (wygrana == false) {
            if (gracz == 'X') {
                gracz = 'O';
            } else {
                gracz = 'X';
            }
        }
    }

    // Wyœwietlenie koñcowej planszy
    cout << "\n1 2 3 4 5 6 7\n";

    for (int i = 0; i < WIERSZE; i++) {
        for (int j = 0; j < KOLUMNY; j++) {
            cout << plansza[i][j] << " ";
        }
        cout << endl;
    }

    if (wygrana == true) {
        cout << "\nWygrywa gracz " << gracz << "!\n";
    } else {
        cout << "\nRemis.\n";
    }

    return 0;
}
