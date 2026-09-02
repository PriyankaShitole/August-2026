#include <iostream>
using namespace std;

namespace Physics {

    double clamp(double val, double min, double max) {

        if (val < min) {
            return min;
        }
        else if (val > max) {
            return max;
        }
        else {
            return val;
        }
    }

    double lerp(double a, double b, double t) {

        return a + (b - a) * t;
    }
}


namespace GameMath {

    int clamp(int val, int min, int max) {

        if (val < min) {
            return min;
        }
        else if (val > max) {
            return max;
        }
        else {
            return val;
        }
    }
}


int main() {

    double result1 = Physics::clamp(150.5, 0.0, 100.0);
    cout << result1 << endl;

    double result2 = Physics::lerp(10, 20, 0.5);
    cout << result2 << endl;

    int result3 = GameMath::clamp(150, 0, 100);
    cout << result3 << endl;

    return 0;
}
