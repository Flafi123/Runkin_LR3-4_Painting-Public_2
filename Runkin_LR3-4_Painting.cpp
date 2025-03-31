#include "Runkin_LR3-4_Painting.h"

// Конструкторы
Painting::Painting() : title(""), author(""), year(0), auctionPrices() {}

Painting::Painting(const string &title, const string &author, int year,
                   const vector<double> &prices)
    : title(title), author(author), year(year), auctionPrices(prices) {}

Painting::Painting(const Painting &other)
    : title(other.title), author(other.author), year(other.year),
      auctionPrices(other.auctionPrices) {}

// Конструктор перемещения
Painting::Painting(Painting &&other) noexcept
    : title(move(other.title)), author(move(other.author)), year(other.year),
      auctionPrices(move(other.auctionPrices)) {
  other.year = 0; // Обнуляем перемещаемый объект
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

// Оператор перемещения
Painting &Painting::operator=(Painting &&other) noexcept {
  if (this != &other) {
    title = move(other.title);
    author = move(other.author);
    year = other.year;
    auctionPrices = move(other.auctionPrices);
    other.year = 0; // Обнуляем перемещаемый объект
  }
  return *this;
}

// Методы get и set
string Painting::getTitle() const { return title; }
void Painting::setTitle(const string &title) { this->title = title; }
string Painting::getAuthor() const { return author; }
void Painting::setAuthor(const string &author) { this->author = author; }
int Painting::getYear() const { return year; }
void Painting::setYear(int year) { this->year = year; }
vector<double> Painting::getAuctionPrices() const { return auctionPrices; }
void Painting::setAuctionPrices(const vector<double> &prices) {
  auctionPrices = prices;
}

// Метод вывода информации о картине
void Painting::display() const {
  cout << "Title: " << title << ", Author: " << author << ", Year: " << year
       << ", Auction Prices: ";
  for (const auto &price : auctionPrices) {
    cout << price << " ";
  }
  cout << endl;
}

// Перегруженные операции
bool Painting::operator<(const Painting &other) const {
  return year < other.year;
}

bool Painting::operator>(const Painting &other) const {
  double thisAvg =
      auctionPrices.empty()
          ? 0
          : accumulate(auctionPrices.begin(), auctionPrices.end(), 0.0) /
                auctionPrices.size();
  double otherAvg = other.auctionPrices.empty()
                        ? 0
                        : accumulate(other.auctionPrices.begin(),
                                     other.auctionPrices.end(), 0.0) /
                              other.auctionPrices.size();
  return thisAvg > otherAvg;
}

Painting Painting::operator+(const Painting &other) const {
  return Painting(title + " & " + other.title, author + " & " + other.author,
                  max(year, other.year), auctionPrices);
}