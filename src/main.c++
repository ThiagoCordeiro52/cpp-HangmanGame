#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    char secretWord[48] = {0};
    char assistantWord[48] = {0};
    char letter;

    int hits = 0;
    int missed = 0;
    int lengthWord = 0;
    int chances = 6;

    cout << "Fale para seu amigo fechar os olhos e digite a palavra secreta: ";
    cin >> secretWord;

    for (int i = 0; i < 48; i++) {
        if (secretWord[i] == '\0') {
            break;
        }
        assistantWord[i] = secretWord[i];
        secretWord[i] = '-';
        lengthWord++;
    }

    if (chances > lengthWord) {
        chances = 3;
    } 

    while (chances != 0 && hits < lengthWord) {
        system("clear||cls");
        missed = 1;
        cout << "Chances restantes: " << chances << endl << endl;
        cout << "Palavra secreta: ";
        for (int i = 0; i < lengthWord; i++) {
            cout << secretWord[i] << " ";
        }
        cout << endl << endl;

        cout << "Digite uma letra: ";
        cin >> letter;

        for (int i = 0; i < lengthWord; i++) {
            if (letter == assistantWord[i]) {
                secretWord[i] = assistantWord[i];
                missed = 0;
                hits++;
            }
        }

        if (missed == 1) {
            chances--;
        }
        
    }

    if (hits == lengthWord) {
        system("clear||cls");
        cout << endl << endl << "Parabéns! Você venceu! 😎" << endl << endl;
    } else {
        system("clear||cls");
        cout << endl << endl << "Que pena! Tente outra vez! Você perdeu. 😭" << endl << endl;
    }

    return 0;
}