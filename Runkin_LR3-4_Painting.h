#ifndef _PAINTING_H // Защита от повторного включения
#define _PAINTING_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Painting {
private:
  std::string title;  // Название картины
  std::string author; // Автор картины
  int year;           // Год создания
  std::vector<double> auctionPrices; // Список предложений цены на аукционе

public:
  // Конструкторы
  Painting(); // Конструктор по умолчанию
  // Painting &operator=(Painting &&) = delete;
  Painting(const std::string &title, int year,
           const std::vector<double> &prices)
      : Painting(title, "", year, prices) {} // Делегирующий конструктор
  Painting(const std::string &title, const std::string &author, int year,
           const std::vector<double> &prices); // Параметризованный конструктор
  Painting(const Painting &other); // Конструктор копирования
  Painting(Painting &&other) noexcept; // Конструктор перемещения
  Painting &operator=(const Painting &other); // Оператор присваивания
  ~Painting();                                // Деструктор

  // Методы get и set
  std::string getTitle() const;
  void setTitle(const std::string &title);
  std::string getAuthor() const;
  void setAuthor(const std::string &author);
  int getYear() const;
  void setYear(int year);
  std::vector<double> getAuctionPrices() const;
  void setAuctionPrices(const std::vector<double> &prices);

  // Метод вывода информации о картине
  void display() const;

  // Перегруженные операции
  bool operator<(const Painting &other) const; // Сравнение по году создания
  double averagePrice() const; // Средняя цена
  bool operator>(const Painting &other) const; // Сравнение по средней цене
  Painting operator+(const Painting &other) const; // Сложение
  Painting &operator++();   // Префиксный инкремент
  Painting operator++(int); // Постфиксный инкремент
  Painting &operator&=(const Painting &other); // Оператор присваивания
};

#endif // _PAINTING_H