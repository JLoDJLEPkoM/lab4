#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void taskFindMinMax();
void taskSwapMinMax();
void taskDistinctCounts();

int main() {
    taskFindMinMax();
    taskSwapMinMax();
    taskDistinctCounts();
    return 0;
}

// 1) Найти максимальный и минимальный элементы вектора
void taskFindMinMax() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mn = a[0], mx = a[0];
    for (int x : a) {
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }
    cout << "min: " << mn << " max: " << mx << endl;
}

// 2) Поменять местами максимальный и минимальный элементы
void taskSwapMinMax() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mn = a[0], mx = a[0], imin = 0, imax = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < mn) { mn = a[i]; imin = i; }
        if (a[i] > mx) { mx = a[i]; imax = i; }
    }
    swap(a[imin], a[imax]);

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << endl;
}

// 3) Количество различных элементов и частоты (без повторений значений)
void taskDistinctCounts() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());

    int distinct = 0;
    vector<pair<int, int>> freq; // (value, count)
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && b[j] == b[i]) ++j;
        freq.push_back({ b[i], j - i });
        distinct++;
        i = j;
    }

    cout << "distinct: " << distinct << endl;
    for (auto& p : freq) {
        cout << p.first << ": " << p.second << endl;
    }
}
