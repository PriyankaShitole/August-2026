#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    int R, C;

    cout << "Enter number of rows: ";
    cin >> R;

    cout << "Enter number of columns: ";
    cin >> C;


    // Dynamic 2D array तयार करणे
    int** map = new int*[R];

    for (int i = 0; i < R; i++) {
        map[i] = new int[C];
    }


    // User कडून values घेणे
    cout << "Enter tile values (0 to 4):" << endl;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }


    // Map print करणे
    cout << "\n===== GAME MAP (" << R << " x " << C << ") =====" << endl;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j] << " ";
        }

        cout << endl;
    }


    // प्रत्येक tile चा count
    int count[5] = {0};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            count[map[i][j]]++;
        }
    }


    // Legend
    cout << "\nLegend:" << endl;
    cout << "0 = Grass" << endl;
    cout << "1 = Water" << endl;
    cout << "2 = Mountain" << endl;
    cout << "3 = Forest" << endl;
    cout << "4 = Dungeon" << endl;


    // Count print
    cout << "\nTile Count:" << endl;
    cout << "Grass: " << count[0] << endl;
    cout << "Water: " << count[1] << endl;
    cout << "Mountain: " << count[2] << endl;
    cout << "Forest: " << count[3] << endl;
    cout << "Dungeon: " << count[4] << endl;


    // Memory delete करणे
    for (int i = 0; i < R; i++) {
        delete[] map[i];
    }

    delete[] map;

    return 0;
}
