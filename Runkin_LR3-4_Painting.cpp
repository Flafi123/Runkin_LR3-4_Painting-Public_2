#include "Runkin_LR3-4_Painting.h"
#include <iostream>
#include <numeric>

// Конструктор по умолчанию
Painting::Painting() : title(""), author(""), year(0), auctionPrices() {}

// Параметризованный конструктор
Painting::Painting(const std::string &title, const std::string &author,
                   int year, const std::vector<double> &prices)
    : title(title), author(author), year(year), auctionPrices(prices) {}

// Конструктор копирования
Painting::Painting(const Painting &other)
    : title(other.title), author(other.author), year(other.year),
      auctionPrices(other.auctionPrices) {}

// Конструктор перемещения
Painting::Painting(Painting &&other) noexcept
    : title(std::move(other.title)), author(std::move(other.author)),
      year(other.year), auctionPrices(std::move(other.auctionPrices)) {
  other.year = 0; // Обнуляем перемещенные данные
}

// Оператор присваивания
Painting &Painting::operator=(const Painting &other) {
  if (this != &other) {
    title = other.title;
    author = other.author;
    year = other.year;
    auctionPrices = other.auctionPrices;
  }
  return *this;
}

// Деструктор
Painting::~Painting() {}

// Методы get и set
std::string Painting::getTitle() const { return title; }
void Painting::setTitle(const std::string &title) { this->title = title; }
std::string Painting::getAuthor() const { return author; }
void Painting::setAuthor(const std::string &author) { this->author = author; }
int Painting::getYear() const { return year; }
void Painting::setYear(int year) { this->year = year; }
std::vector<double> Painting::getAuctionPrices() const { return auctionPrices; }
void Painting::setAuctionPrices(const std::vector<double> &prices) {
  auctionPrices = prices;
}

// Метод вывода информации о картине
void Painting::display() const {
  std::cout << "Title: " << title << ", Author: " << author
            << ", Year: " << year << ", Auction Prices: ";
  for (const auto &price : auctionPrices) {
    std::cout << price << " ";
  }
  std::cout << std::endl;
}

// Перегруженные операции
bool Painting::operator<(const Painting &other) const {
  return year < other.year; // Сравнение по году создания
}

double Painting::averagePrice() const {
  if (auctionPrices.empty())
    return 0.0;
  return std::accumulate(auctionPrices.begin(), auctionPrices.end(), 0.0) /
         auctionPrices.size(); // Средняя цена
}

bool Painting::operator>(const Painting &other) const {
  return averagePrice() > other.averagePrice(); // Сравнение по средней цене
}

Painting Painting::operator+(const Painting &other) const {
  // Создаем новый объект Painting с объединением информации
  std::vector<double> combinedPrices = auctionPrices;
  combinedPrices.insert(combinedPrices.end(), other.auctionPrices.begin(),
                        other.auctionPrices.end());
  return Painting(title + " & " + other.title, author,
                  std::max(year, other.year), combinedPrices);
}

Painting &Painting::operator++() {
  // Префиксный инкремент: увеличиваем год на 1
  year++;
  return *this;
}

Painting Painting::operator++(int) {
  // Постфиксный инкремент: возвращаем копию текущего объекта, затем увеличиваем
  // год
  Painting temp = *this;
  year++;
  return temp;
}

Painting &Painting::operator&=(const Painting &other) {
  if (this != &other) {
    title = other.title;
    author = other.author;
    year = other.year;
    auctionPrices = other.auctionPrices;
  }
  return *this;
}
