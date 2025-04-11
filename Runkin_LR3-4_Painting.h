#ifndef _PAINTING_H // Защита от повторного включения
#define _PAINTING_H
// #include "Runkin_LR3-4_Methods.h"
// #include "Runkin_LR3-4_Methods.cpp"
// #include "Runkin_LR3-4_Painting.cpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Painting {
private:
  string title;  // Название картины
  string author; // Автор картины
  int year;      // Год создания
  vector<double> auctionPrices; // Список предложений цены на аукционе

public:
  // Конструкторы
  Painting(); // Конструктор по умолчанию
  // Painting &operator=(Painting &&) = delete;
  Painting(const string &title, int year, const vector<double> &prices)
      : Painting(title, "", year, prices) {} // Делегирующий конструктор
  Painting(const string &title, const string &author, int year,
           const vector<double> &prices); // Параметризованный конструктор
  Painting(const Painting &other); // Конструктор копирования
  Painting(Painting &&other) noexcept; // Конструктор перемещения

  //

  //

  // Конструктор преобразования
  Painting(const string &t)
      : title(t), author("Anonim"), year(0), auctionPrices(0) {}

  //

  //

  Painting &operator=(const Painting &other); // Оператор присваивания
  ~Painting();                                // Деструктор

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
  bool operator<(const Painting &other) const; // Сравнение по году создания
  double averagePrice() const; // Средняя цена
  bool operator>(const Painting &other) const; // Сравнение по средней цене
  Painting operator+(const Painting &other) const; // Сложение
  // Painting operator+(int additionalYear) const;
  Painting &operator++();   // Префиксный инкремент
  Painting operator++(int); // Постфиксный инкремент
  Painting &operator&=(const Painting &other); // Оператор присваивания
  // Перегруженные операции ввода и вывода
  friend ostream &operator<<(ostream &os, const Painting &painting);
  friend istream &operator>>(istream &is, Painting &painting);
};

#endif // _PAINTING_H