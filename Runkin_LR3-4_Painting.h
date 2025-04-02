#ifndef _POLYNOM_H // Защита от повторного включения
#define _POLYNOM_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Polynom {
  unsigned deg{0};     // степень полинома
  vector<double> koef; // массив коэффициентов
public:
  // конструкторы
  Polynom(); // конструктор
  // параметризованный конструктор со случайными коэффициентами
  Polynom(unsigned k);
  // параметризованный конструктор с заданным массивом коэффициентов
  Polynom(unsigned k, vector<double> mas);
  Polynom(const Polynom &ob); // конструктор копирования
  ~Polynom()                  // деструктор
  {}
  // set-методы
  void setPolynom(unsigned k, const vector<double> &mas) {
    if (k <= mas.size()) {
      deg = k;
      koef.resize(k);
      koef.assign(mas.begin(), mas.begin() + k);
    } else {
      cerr << "Error: Degree exceeds coefficients count." << endl;
    }
  };
  void setDegree(unsigned k) { deg = k; }; // установить степень
  // get-методы
  unsigned getDegree() const { return deg; }; // получить степень
  const vector<double> getKoef() const { return koef; }
  void CalculateValue(double x); // вычисление значения полинома для заданного х
  // перегрузка операторов
  Polynom operator+(const Polynom &other) const;
  const Polynom &operator=(const Polynom &other) {
    // не присваиваем объект самому себе
    if (&other == this)
      return *this;
    deg = other.deg;
    koef = other.koef;
    return *this;
  }
  friend ostream &operator<<(ostream &mystream, const Polynom &obj);
  friend istream &operator>>(istream &mystream, Polynom &obj);
};
#endif // _POLYNOM_H
