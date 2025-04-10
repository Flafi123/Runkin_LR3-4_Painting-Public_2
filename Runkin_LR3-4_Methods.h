#ifndef _METHODS_H // Защита от повторного включения
#define _METHODS_H

#include "Runkin_LR3-4_Painting.h" // Подключаем заголовочный файл с определением класса Painting
#include <string>
#include <vector>

// Глобальный вектор объектов класса Painting
extern std::vector<Painting> paintings;

// Функции проверки корректности входных данных
bool isValidYear(int year);
bool isValidPrice(double price);

// Функции ввода данных с контролем корректности
// std::string inputTitle();
// std::string inputAuthor();
// int inputYear();
// std::vector<double> inputAuctionPrices();

void inputPainting();

// Функция для отображения всех объектов класса
void displayAllPaintings();

// Функция для демонстрации функциональности всех конструкторов
void demonstrateConstructors();

// Функция для демонстрации функциональности всех методов класса
void demonstrateMethods();

// Функция для сортировки картин по году создания
void sortPaintingsByYearCreation();

#endif // _METHODS_H