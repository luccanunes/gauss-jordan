#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int mmc(int a, int b) {
    return a * b / gcd(a, b);
}

struct R {
    int p, q = 1;
    void show() const {
        string s;
        if (q == 1)
            s = to_string(p);
        else
            s = to_string(p) + "/" + to_string(q);
        cout << s;
    }
    R reduct() {
        int g = gcd(p, q);
        while (g != 1) {
            p /= g, q /= g;
            g = gcd(p, q);
        }
        return *this;
    }
    R operator+(const R& x) const {
        if (q == x.q) return R{p + x.p, q}.reduct();
        int qq = mmc(q, x.q);
        return R{qq / q * p + qq / x.q * x.p, qq}.reduct();
    }
    R operator*(const int& x) const {
        return R{x * p, q}.reduct();
    }
    R operator-(const R& x) const {
        return *this + x * -1;
    }
    R operator*(const R& x) const {
        return R{p * x.p, q * x.q}.reduct();
    }
    R operator/(const R& x) const {
        return R{p, q} * R{x.q, x.p};
    }
    void operator*=(const R& x) {
        *this = *this * x;
    }
    void operator/=(const R& x) {
        *this = *this / x;
    }
    void operator+=(const R& x) {
        *this = *this + x;
    }
    bool operator==(const R& x) const {
        return p == x.p && q == x.q;
    }
    bool operator==(const int x) const {
        if (q != 1) return false;
        return p == x;
    }
};

ostream& operator<<(ostream& os, const R& x) {
    x.show();
    return os;
}
istream& operator>>(istream& is, R& x) {
    string s;
    cin >> s;
    auto pos = s.find("/");
    if (pos != string::npos) {
        string p = "", q = "";
        for (int i = 0; i < pos; i++)
            p += s[i];
        for (int i = pos + 1; i < s.size(); i++)
            q += s[i];
        x.p = stoi(p);
        x.q = stoi(q);
    } else {
        x.p = stoi(s);
        x.q = 1;
    }
    return is;
}

struct Matrix {
    int m, n;
    vector<vector<R>> v;
    Matrix(int a, int b) {
        m = a, n = b;
        v.resize(m, vector<R>(n));
    }
    void read() {
        cout << "enter rows:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
    }
    void show() const {
        cout << "-----------\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << left << setw(5) << setfill(' ') << v[i][j] << ' ';
            cout << endl;
        }
        cout << "-----------\n";
    }
    void show_expanded() const {
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
    void multiply_row(int l, R x) {
        l--;
        for (int i = 0; i < n; i++) {
            if (v[l][i] == 0) continue;
            v[l][i] *= x;
        }
    }
    void divide_row(int l, R x) {
        l--;
        for (int i = 0; i < n; i++) {
            if (v[l][i] == 0) continue;
            v[l][i] /= x;
        }
    }
    void add_row(int l, R x, int k) {  // add x*k to l
        l--, k--;
        for (int i = 0; i < n; i++)
            v[l][i] += x * v[k][i];
    }
};

ostream& operator<<(ostream& os, const Matrix& M) {
    M.show_expanded();
    return os;
}

int main() {
    int m, n;
    cout << "dimensions:\n";
    cin >> m >> n;
    Matrix M(m, n);
    M.read();
    cout << M << endl;
    cout << "operations:\n";
    char op;
    int l, k;
    R x;
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
        cout << M << endl;
    }
    return 0;
}