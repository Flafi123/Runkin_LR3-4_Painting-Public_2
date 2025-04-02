#include "Runkin_LR3-4_Methods.h"
#include "Runkin_LR3-4_Painting.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Инициализация глобального вектора
vector<Painting> paintings;

// Функция проверки корректности года
bool isValidYear(int year) {
  return year > 0; // Год должен быть положительным
}

// Функция проверки корректности цены
bool isValidPrice(double price) {
  return price >= 0; // Цена не должна быть отрицательной
}

// Функция ввода названия картины
std::string inputTitle() {
  std::string title;
  cout << "Enter the title of the painting: ";
  cin.ignore(); // Игнорируем предыдущие символы новой строки
  getline(cin, title);
  return title;
}

// Функция ввода автора картины
std::string inputAuthor() {
  std::string author;
  cout << "Enter the author of the painting: ";
  cin.ignore(); // Игнорируем предыдущие символы новой строки
  getline(cin, author);
  return author;
}

// Функция ввода года создания картины с контролем корректности
int inputYear() {
  int year;
  do {
    cout << "Enter the year of the painting's creation (positive integer): ";
    cin >> year;
  } while (!isValidYear(year));
  return year;
}

// Функция ввода списка цен на аукционе
std::vector<double> inputAuctionPrices() {
  std::vector<double> prices;
  int count;
  cout << "Enter the number of prices on the auction: ";
  cin >> count;

  for (int i = 0; i < count; ++i) {
    double price;
    do {
      cout << "Enter price " << (i + 1) << ": ";
      cin >> price;
    } while (!isValidPrice(price));
    prices.push_back(price);
  }
  return prices;
}

// Функция для отображения всех объектов класса
void displayAllPaintings() {
  if (paintings.empty()) {
    cout << "There are no paintings to display." << endl;
    return;
  }
  for (const auto &painting : paintings) {
    painting.display(); // Используем метод display класса Painting
  }
}

// Функция для демонстрации функциональности всех конструкторов
void demonstrateConstructors() {
  cout << "Demonstration of constructors:" << endl;

  // Создаем несколько объектов Painting
  Painting p1; // Конструктор по умолчанию
  Painting p2("Starry Night", "Vincent van Gogh", 1889,
              {100000, 120000, 150000}); // Параметризованный конструктор
  Painting p3(p2);       // Конструктор копирования
  Painting p4 = p2 + p3; // Конструктор преобразования
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

  // Перегруженные операции
  Painting p1 = paintings[0];
  Painting p2 = paintings[1];
  Painting p3 = paintings[2];

  // Сравнение по году создания
  cout << endl << "Comparing paintings by year of creation: " << endl;
  if (p1 < p2) {
    cout << p1.getTitle() << " is older than " << p2.getTitle() << endl;
  } else if (p2 < p1) {
    cout << p2.getTitle() << " is older than " << p1.getTitle() << endl;
  } else {
    cout << p1.getTitle() << " and " << p2.getTitle()
         << " are from the same year" << endl;
  }
  cout << "Comparing paintings by average price: " << endl;

  // Сравнение по средней цене
  if (p2 > p3) {
    cout << p2.getTitle() << " has a higher average price than "
         << p3.getTitle() << endl;
  } else if (p3 > p2) {
    cout << p3.getTitle() << " has a higher average price than "
         << p2.getTitle() << endl;
  } else {
    cout << p2.getTitle() << " and " << p3.getTitle()
         << " have the same average price" << endl;
  }
  cout << endl << "Sum: " << endl;
  // Сложение
  Painting p4 = p1 + p2;
  cout << "The sum of " << p1.getTitle() << " and " << p2.getTitle() << " is "
       << p4.getTitle() << endl;

  cout << endl << endl << "Postfix increment:" << endl;
  // Постфиксный инкремент
  Painting p5 = paintings[0];
  Painting p6 = p5++;
  cout << p6.getYear() << " is the same as " << p5.getYear() << endl;

  cout << endl << endl << "Prefix increment:" << endl;
  // Префиксный инкремент
  Painting p7 = ++p6;
  cout << p7.getYear() << " is the same as " << p6.getYear() << endl;

  // НЕРАБОТАЕТ Я ХЗ
  // cout << endl << endl << "Assignment:" << endl;
  // // Присваивание
  // Painting p8 = p3;
  // cout << p8.getTitle() << " is the same as " << p3.getTitle() << endl;
}

// Функция для сортировки картин по году создания
void sortPaintingsByYearCreation() {
  cout << "Sorting paintings by year of creation:" << endl;
  std::sort(paintings.begin(), paintings.end(),
            [](const Painting &a, const Painting &b) { return a < b; });
  displayAllPaintings();
}
