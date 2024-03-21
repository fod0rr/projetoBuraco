//projeto Buraco

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

vector<string> inicializarBaralho() {
    vector<string> baralho;
    string naipes[4] = {"1", "2", "3", "4"};
    string numeros[13] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13"};

    for (int n = 0; n < 4; ++n) {
        for (int c = 0; c < 13; ++c) {
            for (int b = 1; b <= 2; ++b) {
                baralho.push_back(naipes[n] + "-" + numeros[c] + "-" + to_string(b));
            }
        }
    }

    return baralho;
}

void distribuirCartas(vector<string>& baralho, vector<vector<string>>& mao) {
    srand(time(0));
    random_shuffle(baralho.begin(), baralho.end());

    for (int j = 0; j < 4; ++j) {
        for (int c = 0; c < 11; ++c) {
            mao[j][c] = baralho[j * 11 + c];
        }
    }
}

void mostrarMaos(const vector<vector<string>>& mao) {
    for (int j = 0; j < 4; ++j) {
        cout << "Mão do jogador " << j+1 << ":" << endl;
        for (int c = 0; c < 11; ++c) {
            cout << mao[j][c] << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<string> baralho = inicializarBaralho();
    vector<vector<string>> mao(4, vector<string>(11));

    distribuirCartas(baralho, mao);
    mostrarMaos(mao);

    return 0;
}
