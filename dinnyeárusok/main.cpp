#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int emberek_hossz;
    cin >> emberek_hossz;

    int emberek[emberek_hossz];

    for (int i = 0; i < emberek_hossz; i++) {
        cin >> emberek[i];
    }

    int helyek_hossz;
    cin >> helyek_hossz;

    int helyek[helyek_hossz];

    for (int i = 0; i < helyek_hossz; i++) {
        cin >> helyek[i];
    }

    int max_tav;
    cin >> max_tav;

    int veg = 0;

    int ember_i = 0;
    int hely_i = 0;

    while (ember_i < emberek_hossz && hely_i < helyek_hossz) {
        int tav = abs(emberek[ember_i] - helyek[hely_i]);

        if (tav <= max_tav) {
            ember_i++;
            hely_i++;

            veg++;
        } else if (emberek[ember_i] < helyek[hely_i]) {
            ember_i++;

        } else {
            hely_i++;
        }
    }

    cout << veg << endl;

    return 0;
}
