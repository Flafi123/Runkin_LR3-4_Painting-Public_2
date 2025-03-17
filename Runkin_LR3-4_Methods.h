#ifndef RUNKIN_LR3_4_METHODS_H
#define RUNKIN_LR3_4_METHODS_H

#include "Runkin_LR3-4_Painting.h"

using namespace std;

vector<Painting> paintings;

bool isValidYear(int year) {
  return year > 0; // Пример проверки
}

bool isValidPrice(double price) {
  return price >= 0; // Пример проверки
}

void displayAllPaintings() {
  for (const auto &painting : paintings) {
    painting.display();
  }
}

void addPainting(const Painting &painting) { paintings.push_back(painting); }

vector<Painting> getSortedByYear() {
  vector<Painting> sortedPaintings = paintings;
  sort(sortedPaintings.begin(), sortedPaintings.end());
  return sortedPaintings;
}

#endif // RUNKIN_LR3_4_METHODS_H