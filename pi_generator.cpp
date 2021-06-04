#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

int countNum = 0;
int countOfPointsInside = 0;
int countOfPointsOutside = 0;
int countOfPointsOn = 0;
float point[2];

int main() {
    cout << "Welcome in PI generator app written in C++ by Lukas Podolak" << endl;
    cout << "www.lukas.podolak.tech" << endl << endl;

    cout << "Enter the count of random generated numbers for PI calculation: ";
    cin >> countNum;

    srand((unsigned)time(NULL));

    for (int i = 0; i < countNum; i++) {
        point[0] = (float) rand()/RAND_MAX;
        point[1] = (float) rand()/RAND_MAX;

        if (pow(point[0], 2) + pow(point[1], 2) - 1 < 0) {
            countOfPointsInside++;
        } else if (pow(point[0], 2) + pow(point[1], 2) - 1 == 0) {
            countOfPointsOn++;
        } else {
            countOfPointsOutside++;
        }
    }

    cout << endl << "In - " << countOfPointsInside << endl;
    cout << "Out - " << countOfPointsOutside << endl;
    cout << "On - " << countOfPointsOn << endl << endl;

    cout << "PI = " << (4.0f * countOfPointsInside) / countNum;

    return 0;
}