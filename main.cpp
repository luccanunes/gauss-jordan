#include <bits/stdc++.h>

using namespace std;

struct Matrix {
    int m, n;
    vector<vector<double>> v;
    Matrix(int a, int b) {
        m = a, n = b;
        v.resize(m, vector<double>(n));
    }
    void read() {
        cout << "enter rows:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
    }
    void show() {
        cout << "-----------\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << left << setw(5) << setfill(' ') << v[i][j] << ' ';
            cout << endl;
        }
        cout << "-----------\n";
    }
    void show_expanded() {
        cout << "-----------\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++)
                cout << left << setw(5) << setfill(' ') << v[i][j] << ' ';
            cout << left << setw(5) << setfill(' ') << "| " << v[i][n - 1] << endl;
        }
        cout << "-----------\n";
    }
    void swap_rows(int l, int k) {
        l--, k--;
        for (int i = 0; i < n; i++)
            swap(v[l][i], v[k][i]);
    }
    void multiply_row(int l, double x) {
        l--;
        for (int i = 0; i < n; i++)
            v[l][i] *= x;
    }
    void divide_row(int l, double x) {
        l--;
        for (int i = 0; i < n; i++)
            v[l][i] /= x;
    }
    void add_row(int l, double x, int k) {  // add x*k to l
        l--, k--;
        for (int i = 0; i < n; i++)
            v[l][i] += x * v[k][i];
    }
};

int main() {
    int m, n;
    cout << "dimensions:\n";
    cin >> m >> n;
    Matrix M(m, n);
    M.read();
    M.show_expanded();
    cout << "operations:\n";
    char op;
    int l, k;
    double x;
    while (true) {
        cin >> op;
        if (op == 'S' || op == 's') {
            cin >> l >> k;
            M.swap_rows(l, k);
        } else if (op == 'M' || op == 'm') {
            cin >> l >> x;
            M.multiply_row(l, x);
        } else if (op == 'D' || op == 'd') {
            cin >> l >> x;
            M.divide_row(l, x);
        } else if (op == 'A' || op == 'a') {
            cin >> l >> x >> k;
            M.add_row(l, x, k);
        }
        M.show_expanded();
    }
    return 0;
}