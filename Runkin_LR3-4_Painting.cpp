#include "Runkin_LR3-4_Methods.h"
#include <cmath>
#include <iomanip>

// конструкторы
Polynom::Polynom() {
  deg = rand() % 5 + 1; // получение случайной степени полинома
  koef.resize(
      deg,
      0); // изменение размера вектора с установлением значения по умолчанию 0
  // установление элементам вектора случайных значений
  generate(koef.begin(), koef.end(), []() { return rand() % 100; });
}

Polynom::Polynom(unsigned k) {
  deg = k; // создание полинома с заданной степенью
  koef.resize(
      deg,
      0); // изменение размера вектора с установлением значения по умолчанию 0
  // установление элементам вектора случайных значений
  generate(koef.begin(), koef.end(), []() { return rand() % 100; });
}

// создание полинома заданной степени с заданным массивом коэффициентов
Polynom::Polynom(unsigned k, vector<double> mas) : Polynom(k) {
  setPolynom(k, mas);
}

// создание полинома путем копирования
Polynom::Polynom(const Polynom &other) : deg(other.deg), koef(other.koef) {}

void Polynom::CalculateValue(double x = 1.0) {
  double s = koef[0];
  for (int i = 1; i <= deg; i++)
    s += koef[i] * pow(x, i);
  cout << "f(" << x << ") = " << s << endl;
}

// переопределение операции сложения
Polynom Polynom::operator+(const Polynom &other) const {
  Polynom result;
  result.deg = max(deg, other.deg); // Максимальная степень результата
  result.koef.resize(result.deg + 1, 0.0); // Размер вектора = степень + 1
  // Складываем коэффициенты при одинаковых степенях
  for (unsigned exponent = 0; exponent <= result.deg; ++exponent) {
    double this_coeff = (exponent <= deg) ? koef[deg - exponent] : 0.0;
    double other_coeff =
        (exponent <= other.deg) ? other.koef[other.deg - exponent] : 0.0;
    result.koef[result.deg - exponent] = this_coeff + other_coeff;
  }
  return result;
}

// переопределение оператора вывода на консоль
ostream &operator<<(ostream &mystream, const Polynom &obj) {
  bool firstTerm = true; // флаг для первого члена полинома
  for (size_t i = 0; i < obj.koef.size(); i++) {
    double coeff = obj.koef[i];
    if (abs(coeff) < 1e-10)
      continue; // Пропускаем нулевые коэффициенты
    if (!firstTerm)
      mystream << (coeff > 0 ? "+" : "-");
    else {
      if (coeff < 0)
        mystream << "-";
      firstTerm = false;
    }
    double absCoeff = abs(coeff);
    if (absCoeff != 1.0 || i == obj.koef.size() - 1)
      mystream << fixed << setprecision(2) << absCoeff;
    if (i < obj.koef.size() - 1) {
      mystream << "x";
      if (i < obj.koef.size() - 2)
        mystream << "^" << (obj.koef.size() - 1 - i);
    }
  }
  if (firstTerm)
    mystream << "0";
  return mystream;
}

// переопределение оператора ввода с консоли
istream &operator>>(istream &mystream, Polynom &obj) {
  string st;
  cout << "Enter Degree: ";
  getline(mystream, st);
  obj.deg = stoi(st);
  obj.koef.clear();
  for (int i = obj.deg; i >= 0; i--) {
    cout << "Enter koeff " << i << ": ";
    getline(mystream, st);
    obj.koef.push_back(stod(st));
  }
  return mystream;
}