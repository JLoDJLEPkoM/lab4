#include <iostream>
#include <cmath>
using namespace std;

void findMinAbsIndex();
void sumAfterFirstNegative();
void compressArray();

int main() {
    findMinAbsIndex();
    sumAfterFirstNegative();
    compressArray();
    return 0;
}

void findMinAbsIndex() {
    int n;
    cin >> n;
    double data[1000];
    for (int i = 0; i < n; ++i) cin >> data[i];

    int minNumber = 0;
    double minValue = fabs(data[0]);
    for (int i = 1; i < n; ++i)
        if (fabs(data[i]) < minValue) {
            minValue = fabs(data[i]);
            minNumber = i;
        }

    cout << "result: " << minNumber + 1 << endl;
}

void sumAfterFirstNegative() {
    int n;
    cin >> n;
    double data[1000];
    for (int i = 0; i < n; i++) cin >> data[i];

    double sum = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (found) sum += fabs(data[i]);
        if (data[i] < 0 && !found) found = true;
    }

    cout << "result: " << sum << endl;
}

void compressArray() {
    int n;
    cin >> n;
    double data[1000];
    for (int i = 0; i < n; i++) cin >> data[i];

    int k = 0;
    for (int i = 0; i < n; i++)
        if (data[i] < -2 || data[i] > 2)
            data[k++] = data[i];

    for (int i = k; i < n; i++)
        data[i] = 0;
    cout << "result: ";
    for (int i = 0; i < n; i++)
        
        cout << data[i] << " ";
        
    cout << endl;
}
