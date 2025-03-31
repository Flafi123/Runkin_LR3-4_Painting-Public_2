#ifndef RUNKIN_LR3_4_PAINTING_H
#define RUNKIN_LR3_4_PAINTING_H

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

using namespace std;

class Painting {
private:
  string title;
  string author;
  int year;
  vector<double> auctionPrices;

public:
  // Конструкторы
  void addPainting(const Painting &painting);

  // Метод для отображения всех картин
  void displayAllPaintings() const;
  Painting(); // Конструктор по умолчанию
  Painting(const string &title, const string &author, int year,
           const vector<double> &prices);
  Painting(const Painting &other); // Конструктор копирования
  Painting(Painting &&other) noexcept; // Конструктор перемещения (с noexcept)

  // Операторы
  Painting &operator=(const Painting &other); // Оператор присваивания
  Painting &
  operator=(Painting &&other) noexcept; // Оператор перемещения (с noexcept)

  // Методы get и set
  string getTitle() const;
  void setTitle(const string &title);
  string getAuthor() const;
  void setAuthor(const string &author);
  int getYear() const;
  void setYear(int year);
  vector<double> getAuctionPrices() const;
  void setAuctionPrices(const vector<double> &prices);

  // Метод вывода информации о картине
  void display() const;

  // Перегруженные операции
  bool operator<(const Painting &other) const;
  bool operator>(const Painting &other) const;
  Painting operator+(const Painting &other) const;
};

#endif // RUNKIN_LR3_4_PAINTING_H