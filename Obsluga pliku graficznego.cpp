#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

void analyzeImage(const string& filename) {
    ifstream file(filename);
    string line;
    int maxPixelValue = -1;

    if (file.is_open()) {
        getline(file, line);
        if (line != "P1" && line != "P2") {
            cout << "Niepoprawny format pliku." << endl;
            return;
        }

        bool isPBM = (line == "P1");

        int width, height;
        file >> width >> height;
        cout << "Szerokosc obrazu: " << width << endl;
        cout << "Wysokosc obrazu: " << height << endl;

        if (!isPBM) {
            file >> maxPixelValue;
        }

        unordered_map<int, int> colorFrequency;
        int pixel;
        while (file >> pixel) {
            colorFrequency[pixel]++;
        }

        int mostFrequentPixel = -1;
        int maxFrequency = -1;
        for (const auto& kvp : colorFrequency) {
            if (kvp.second > maxFrequency) {
                mostFrequentPixel = kvp.first;
                maxFrequency = kvp.second;
            }
        }

        cout << "Najczesciej wystepujacy kolor to: " << mostFrequentPixel << " i wystapil " << maxFrequency << " razy" << endl;
        cout << "Liczba unikalnych kolorow: " << colorFrequency.size() << endl;
    } else {
        cout << "Nie mozna otworzyc pliku." << endl;
    }
}

int main() {
    while (true) {
        string filename;
        cout << "Podaj nazwe pliku: ";
        cin >> filename;

        analyzeImage(filename);

        string answer;
        cout << "Czy chcesz wczytac kolejny plik (tak/nie): ";
        cin >> answer;
        if (answer != "tak") {
            break;
        }
    }

    return 0;
}
