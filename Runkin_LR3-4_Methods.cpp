#include "Runkin_LR3-4_Methods.h"
#include "Runkin_LR3-4_Painting.h"
#include <algorithm>
#include <iostream>
using namespace std;

// Инициализация глобального вектора
vector<Painting> paintings;

bool isValidNumber(const string &input) {
  if (input.empty())
    return false; // Пустая строка не является корректным числом
  for (char c : input) {
    if (!isdigit(c))
      return false; // Разрешаем только положительные числа
  }

  return true;
}

// Функция для ввода числа
void EnterNumber(int &varLink, const string &label) {
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
}

bool isNonEmptyString(const string &input) { return !input.empty(); }

// Функция для ввода числа
void EnterString(string &varLink, const string &label) {
  string raw_input;
  cout << label;
  getline(cin, raw_input);

  // Цикл для повторного запроса числа, пока не будет введено корректное
  // значение
  while (!isNonEmptyString(raw_input)) {
    cout << "Invalid input. " << label;
    getline(cin, raw_input);
  }

  varLink = raw_input; // на выходе должна быть строка
}

// Функция проверки корректности года
bool isValidYear(int year) {
  return year > 0; // Год должен быть положительным
}

// Функция проверки корректности цены
bool isValidPrice(double price) {
  return price >= 0; // Цена не должна быть отрицательной
}

// Функция ввода картины
void inputPainting() {
  Painting p;
  cin >> p;
  paintings.push_back(p);
}

// Функция для отображения всех объектов класса
void displayAllPaintings() {
  if (paintings.empty()) {
    cout << "There are no paintings to display." << endl;
    return;
  }
  for (const auto &painting : paintings) {
    cout << painting << endl; // Используем перегруженную операцию вывода
  }
}
int getValidIndex() {
  int index;
  while (true) {
    cout << "Enter the index of a painting: ";
    string raw_input;
    cin >> raw_input;

    if (!isValidNumber(raw_input)) {
      cout << "Invalid input. Number expected." << endl;
      continue;
    }

    index = stoi(raw_input);

    if (index < 1 || index > paintings.size()) {
      cout << "Invalid index." << endl;
      continue;
    }

    return index - 1;
  }
}

// Функция для демонстрации функциональности всех конструкторов
void demonstrateConstructors() {
  cout << "Demonstration of constructors:" << endl;

  // Создаем несколько объектов Painting
  Painting p1; // Конструктор по умолчанию
  Painting p2("Starry Night", "Vincent van Gogh", 1889,
              {100000, 120000, 150000}); // Параметризованный конструктор
  Painting p3(p2); // Конструктор копирования
  // Painting p4 = p2 + 100; // Конструктор преобразования
  Painting p4("Transformers"); // Конструктор преобразования
  Painting p5("The Starry Night", 1889,
              {100000, 120000, 150000}); // Делегирующий конструктор

  // Добавляем картины в вектор

  paintings.push_back(p2);
  paintings.push_back(p1);
  paintings.push_back(p3);
  paintings.push_back(p4);
  paintings.push_back(p5);

  // Отображаем все картины
  displayAllPaintings();
}

// Функция для демонстрации функциональности всех методов класса
void demonstrateMethods() {
  cout << "Demonstrating methods:" << endl;

  if (paintings.empty()) {
    cout << "No paintings to demonstrate methods." << endl;
    return;
  }

  // Сравнение по году создания
  int q3_index = getValidIndex();
  int q4_index = getValidIndex();
  Painting q3 = paintings[q3_index];
  Painting q4 = paintings[q4_index];

  cout << endl << "Comparing paintings by year of creation: " << endl;
  if (q4 < q3) {
    cout << q3.getTitle() << " is older than " << q4.getTitle() << endl;
  } else if (q4 < q3) {
    cout << q4.getTitle() << " is older than " << q3.getTitle() << endl;
  } else {
    cout << q3.getTitle() << " and " << q4.getTitle()
         << " are from the same year" << endl;
  }

  cout << endl << "Comparing paintings by average price: " << endl;
  int q5_index = getValidIndex();
  int q6_index = getValidIndex();
  Painting q5 = paintings[q5_index];
  Painting q6 = paintings[q6_index];

  if (q5 > q6) {
    cout << q5.getTitle() << " has a higher average price than "
         << q6.getTitle() << endl;
  } else if (q6 > q5) {
    cout << q6.getTitle() << " has a higher average price than "
         << q5.getTitle() << endl;
  } else {
    cout << q5.getTitle() << " and " << q6.getTitle()
         << " have the same average price" << endl;
  }
  //
  cout << endl << "Displaying all paintings:" << endl;
  displayAllPaintings();
  cout << endl;
  //
  cout << endl << "Sum: " << endl;
  int s1_index = getValidIndex();
  int s2_index = getValidIndex();

  Painting s1 = paintings[s1_index];
  Painting s2 = paintings[s2_index];
  Painting s4 = s1 + s2;
  cout << "The sum of " << s1.getTitle() << " and " << s2.getTitle() << " is "
       << s4.getTitle() << endl;
  cout << s4;
  paintings.push_back(s4);
  //
  cout << endl << "Displaying all paintings:" << endl;
  displayAllPaintings();
  cout << endl;
  //
  cout << endl << endl << "Postfix increment:" << endl;
  int i5_index = getValidIndex();

  Painting i5 = paintings[i5_index];
  Painting i6 = i5++;
  cout << i6.getYear() << " is the same as " << i5.getYear() << endl;
  paintings.push_back(i6);
  //
  cout << endl << "Displaying all paintings:" << endl;
  displayAllPaintings();
  cout << endl;
  cout << endl << endl << "Prefix increment:" << endl;
  int i7_index = getValidIndex();
  Painting i7 = paintings[i7_index];
  Painting i8 = ++i7;
  cout << i8.getYear() << " is the same as " << i7.getYear() << endl;
  paintings.push_back(i8);
  //
  cout << endl << "Displaying all paintings:" << endl;
  displayAllPaintings();
  cout << endl;
  cout << endl << "averagePrice:" << endl;
  int a8_index = getValidIndex();
  Painting p8 = paintings[a8_index];
  cout << p8.averagePrice() << endl;

  // Функция для сортировки картин по году создания
}

void sortPaintingsByYearCreation() {
  cout << "Sorting paintings by year of creation:" << endl;
  std::sort(paintings.begin(), paintings.end(),
            [](const Painting &a, const Painting &b) { return a < b; });
  displayAllPaintings();
}
