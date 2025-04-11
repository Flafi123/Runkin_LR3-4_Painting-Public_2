#include "Runkin_LR3-4_Painting.h"
// #include "Runkin_LR3-4_Methods.cpp"
#include "Runkin_LR3-4_Methods.h"
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
  return year > other.year; // Сравнение по году создания
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
  // Создаем новый объект Painting с суммой параметров
  std::vector<double> combinedPrices = auctionPrices;
  combinedPrices.insert(combinedPrices.end(), other.auctionPrices.begin(),
                        other.auctionPrices.end());
  return Painting(title + " & " + other.title, author + " & " + other.author,
                  year + other.year, combinedPrices);
}
// Painting Painting::operator+(int additionalYear) const {
//   // Создаем новый объект Painting с увеличенным годом
//   Painting result;
//   result.title = title;
//   result.author = author;
//   result.year = year + additionalYear;
//   result.auctionPrices = auctionPrices;
//   return result;
// }

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
// Перегруженный оператор ввода
std::istream &operator>>(std::istream &is, Painting &painting) {

  cin.ignore();

  EnterString(painting.title, "Enter title: ");
  EnterString(painting.author, "Enter author: ");
  EnterNumber(painting.year, "Enter year: ");
  int count1;
  EnterNumber(count1, "Enter number of auction prices: ");
  std::size_t count = count1;
  painting.auctionPrices.resize(count);
  for (std::size_t i = 0; i < count; ++i) {
    int price;
    EnterNumber(price, "Enter price " + std::to_string(i + 1) + ": ");
    painting.auctionPrices[i] = price;
  }
  return is;
}

std::ostream &operator<<(ostream &os, const Painting &painting) {
  os << "Title: " << painting.title << ", Author: " << painting.author
     << ", Year: " << painting.year << ", Auction Prices: ";
  for (const auto &price : painting.auctionPrices) {
    os << price << " ";
  }
  return os;
}
