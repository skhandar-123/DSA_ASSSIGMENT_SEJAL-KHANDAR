#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "ABRACADABRA";
    int freq[256] = {0};

    // Count frequency
    for(int i = 0; i < s.length(); i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Store unique characters
    char chars[256];
    int f[256];
    int n = 0;

    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            chars[n] = (char)i;
            f[n] = freq[i];
            n++;
        }
    }

    // Simple bubble sort based on frequency (small to high)
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(f[i] > f[j]) {
                swap(f[i], f[j]);
                swap(chars[i], chars[j]);
            }
        }
    }

    // Assign simple Huffman-like codes
    cout << "Character\tFrequency\tCode\n";
    for(int i = 0; i < n; i++) {
        cout << chars[i] << "\t\t" << f[i] << "\t\t";

        // smaller freq = longer code
        for(int k = 0; k <= i; k++) cout << "1";
        cout << "0";

        cout << endl;
    }

    return 0;
}
