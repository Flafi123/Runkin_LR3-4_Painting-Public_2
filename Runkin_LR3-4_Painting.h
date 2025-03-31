#ifndef RUNKIN_LR3_4_PAINTING_H
#define RUNKIN_LR3_4_PAINTING_H

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
  Painting();
  Painting(const string &title, const string &author, int year,
           const vector<double> &prices);
  Painting(const Painting &other); // Конструктор копирования
  Painting(Painting &&other); // Конструктор перемещения
  Painting &operator=(const Painting &other); // Оператор присваивания

  string getTitle() const;
  string getAuthor() const;
  int getYear() const;
  vector<double> getAuctionPrices() const;
  //
  void setAuctionPrices(const vector<double> &prices);
  void setTitle(const string &title);
  void setAuthor(const string &author);
  void display() const;
  void setYear(int year);

  bool operator<(const Painting &other) const; // Сравнение по году создания
  bool operator>(const Painting &other) const; // Сравнение по средней цене
  Painting operator+(const Painting &other) const; // Сложение
  function<void()> EnterNumber(int &varLink, string label);
};

#endif // RUNKIN_LR3_4_PAINTING_H