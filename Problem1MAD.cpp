#include <iostream>
#include <string>
using namespace std;

bool kiemtrakytu(char c) {
    return (c == 'a' || c == 'b' || c == 'c' || c == 'd');
}


bool kiemtrachuoi(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!kiemtrakytu(s[i])) return false;
    }
    return true;
}

char kytutieptheo(char c) {
    if (c == 'a') return 'b';
    if (c == 'b') return 'c';
    if (c == 'c') return 'd';
    return 'a';
}


string chuoitieptheo(string s) {
    int i = s.length() - 1;

    while (i >= 0 && s[i] == 'd') {
        s[i] = 'a';
        i--;
    }

    if (i < 0) {
        return string(s.length() + 1, 'a');
    }

    s[i] = kytutieptheo(s[i]);
    return s;
}

bool Wavy(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (i % 2 == 0) {
            if (!(s[i] < s[i + 1])) return false;
        } else {
            if (!(s[i] > s[i + 1])) return false;
        }
    }
    return true;
}

string nextWavy(string s) {
    string t = chuoitieptheo(s);
    while (!Wavy(t)) {
        t = chuoitieptheo(t);
    }
    return t;
}

int countWavyBefore(string s) {
    int n = s.length();
    string cur(n, 'a');
    int count = 0;

    while (cur != s) {
        if (Wavy(cur)) count++;
        cur = chuoitieptheo(cur);
    }

    return count;
}

bool chuoicon(string a, string b) {
    for (int i = 0; i <= a.length() - b.length(); i++) {
        bool ok = true;
        for (int j = 0; j < b.length(); j++) {
            if (a[i + j] != b[j]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

int demdodaichuoi(int n, string s) {
    string cur(n, 'a');
    int count = 0;

    while (true) {
        if (chuoicon(cur, s)) count++;

        if (cur == string(n, 'd')) break;
        cur = chuoitieptheo(cur);
    }

    return count;
}

int main() {
    string s;
    int n;

    cout << "Nhap chuoi s: ";
    cin >> s;
    if (!kiemtrachuoi(s)) {
        cout << "Chuoi khong thuoc tap A = {a, b, c, d}" << endl;
        return 0;
    }

    cout << " 1.1 Next(s): " << chuoitieptheo(s) << endl;

    cout << " 1.2 Wavy tiep theo: " << nextWavy(s) << endl;

    cout << " 1.3 So wavy dung truoc s: " << countWavyBefore(s) << endl;

    cout << " 1.4 Nhap n: ";
    cin >> n;

    cout << "So chuoi do dai n chua s: " << demdodaichuoi(n, s) << endl;

    return 0;
}