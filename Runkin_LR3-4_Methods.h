#ifndef RUNKIN_LR3_4_METHODS_H
#define RUNKIN_LR3_4_METHODS_H
#include "Runkin_LR3-4_Painting.h"

using namespace std;

vector<Painting> paintings;

bool isValidNumber(const string &input) {
  if (input.empty())
    return false; // Пустая строка не является корректным числом
  for (char c : input) {
    if (!isdigit(c) && c != '-')
      return false; // Разрешаем отрицательные числа
  }
  return true;
}

// Функция для ввода числа
function<void()> EnterNumber(int &varLink, string label) {
  return [&varLink, label]() {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    // Цикл для повторного запроса числа, пока не будет введено корректное
    // значение
    while (!isValidNumber(raw_input)) {
      cout << "Invalid input. " << label;
      getline(cin, raw_input);
    }

    varLink = stoi(raw_input); // Преобразуем строку в целое число
  };
}

void loadFile(const string &fileName, vector<Painting> &paintings) {
  ifstream inFile(fileName);
  if (!inFile) {
    cout << "Ошибка открытия файла: " << fileName << endl;
    return;
  }

  string title, author;
  int year;
  double price;
  vector<double> prices;

  while (inFile >> ws && getline(inFile, title, ',') &&
         getline(inFile, author, ',') && inFile >> year) {
    prices.clear();
    while (inFile >> price) {
      prices.push_back(price);
      if (inFile.peek() == '\n' || inFile.eof())
        break; // Прекращаем, если достигли конца строки или файла
    }
    paintings.push_back(Painting(title, author, year, prices));
  }

  inFile.close();
  cout << "Файл загружен успешно!" << endl;
}

bool isValidYear(int year) {
  int i;

  return year > i;
}

// bool isValidPrice(double price) { return price >= 0; }

void displayAllPaintings() {
  for (const auto &painting : paintings) {
    painting.display();
  }
}

void addPainting(const Painting &painting) { paintings.push_back(painting); }

vector<Painting> getSortedByYear() {
  vector<Painting> sortedPaintings = paintings;
  sort(sortedPaintings.begin(), sortedPaintings.end());
  return sortedPaintings;
}

#endif // RUNKIN_LR3_4_METHODS_H