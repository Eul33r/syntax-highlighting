#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

// Funkcja kolorująca tekst na czerwono
string red(const string& text) {
    return "\033[31m" + text + "\033[0m";
}
string orange(const string& text) {
    return "\033[38;5;208m" + text + "\033[0m";
}

// Funkcja kolorująca tekst na zielono
string green(const string& text) {
    return "\033[32m" + text + "\033[0m";
}

// Funkcja sprawdzająca, czy dany ciąg znaków jest słowem kluczowym
bool isType(const string& word) {
    vector<string> types = {"int", "double", "float", "char", "bool", "long"};
    for (const auto& types : types) {
        if (word == types || (word == "long" && types == "unsigned")) {
            return true;
        }
    }
    return false;
}
bool isKeyword(const string& word) {
    vector<string> keywords = {"if", "else", "return", "for", "while", "do", "switch", "case", "break", "continue", "const"};
    for (const auto& keyword : keywords) {
        if (word == keyword || (word == "long" && keyword == "unsigned")) {
            return true;
        }
    }
    return false;
}

int main() {

    system(("chcp "s + std::to_string(CP_UTF8)).c_str());

    // Nazwa pliku do kolorowania
    string filename = "Program.txt";

    cout << "Otwieranie pliku: " << filename << endl;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nie można otworzyć pliku: " << filename << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        while (pos < line.size()) {
            // Pomijanie białych znaków
            while (pos < line.size() && isspace(line[pos])) {
                cout << line[pos];
                pos++;
            }
            // Kolorowanie słów kluczowych
            string word;
            while (pos < line.size() && !isspace(line[pos])) {
                word += line[pos];
                pos++;
            }
            if (isKeyword(word)) {
                cout << orange(word);
            } else if(isType(word)){
                cout << green(word);
            } else cout << word;
        }
        cout << endl;
    }

   // file.close();
    return 0;
}
