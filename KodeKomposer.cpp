#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long calculateUniquePermutations(const string &str) {
    map<char, int> freq;
    for (char c : str) {
        if (c != ' ') { 
            freq[c]++;
        }
    }

    long long numerator = factorial(str.size() - count(str.begin(), str.end(), ' '));  
    long long denominator = 1;

    for (const auto &pair : freq) {
        denominator *= factorial(pair.second); 
    }

    return numerator / denominator;
}

void generatePermutations(const string &str, vector<string> &permutations) {
    string s = str;
    sort(s.begin(), s.end());  
    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
}

void savePermutationsToFile(const vector<string> &permutations, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &perm : permutations) {
            file << perm << endl;
        }
        file.close();
        cout << "Permutasi berhasil disimpan di " << filename << endl;
        cout <<"setatus selesai."<<endl;

    } else {
        cerr << "Tidak bisa membuka file untuk menulis." << endl;
    }
}

int main() {
    string input;
    vector<string> permutations;
    string garis = "+===============================================================+\n";
    cout << garis;
   cout << "|\t\t\tMesin Pencari Kode\t\t\t|\n";
    cout << "|\tCukup tuliskan kode yang anda inginkan \t\t\t|\n";
    cout << "|\tMesin ini akan membuatkan beberapa kombinasi yang cocok\t|\n";
    cout << "|\tExample: 'liyoe1uov' dan kode aslinya '1iloveyou'\t|\n";
    cout << "|\tAkan secara otomatis dibuatkan\t\t\t\t|\n";
    cout << "|\tfile disimpan dengan nama permutasi.txt\t\t\t|\n";
    cout << "|\t\t\t\t\t\t\t\t|\n";
    cout << "|\tIG:aditiya.subakti\t|in:aditiya subakti\t\t|\n";
    cout << garis;
    
    cout << "Masukkan string: ";
    getline(cin, input);
    cout << "Input yang diterima: " << input << endl;

    long long uniquePermutations = calculateUniquePermutations(input);
    cout << "Permutasi unik yang diharapkan: " << uniquePermutations << endl;
    cout <<"\nsedang proses permutasi...\n"<<endl;

    generatePermutations(input, permutations);

    cout << "Jumlah permutasi yang dihasilkan: " << permutations.size() << endl;

    savePermutationsToFile(permutations, "permutasi.txt");

    cout << "\nTekan Enter untuk keluar...";
    cin.get();  // Menunggu user menekan Enter

    return 0;
}

