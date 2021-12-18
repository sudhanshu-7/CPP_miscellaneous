#include <bits/stdc++.h>
using namespace std;
vector <int> generate_pi(string s) {
    vector <int> pi (s.length());
    pi[0] = 0;
    for (int i = 1; i < s.length (); ++i) {
        int prev = pi[i - 1];
        while (prev > 0 && s[prev] != s[i]) {
            prev = pi[prev - 1];
        }
        if (s[prev] == s[i]) prev ++;
        pi[i] = prev;
    }
    return pi;
}
int main() {
    string text , pattern;
    cin >> text >> pattern;
    vector <int> pi = generate_pi(pattern);
    int cnt = 0;
    for (int i = 0; i < text.length(); ++i) {
        while (cnt > 0 && pattern[cnt] != text[i]) {
            cnt = pi[cnt - 1];
        }
        if (pattern[cnt] == text[i]) cnt++;
        if (cnt == pattern.length()) {
            cout << "FOUND AT INDEX : " << i - pattern.length() + 1 << endl;
            cnt = pi.back();
        }
    }
    return 0;
}