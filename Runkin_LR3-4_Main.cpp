#include "Runkin_LR3-4_Methods.cpp"
#include "Runkin_LR3-4_Methods.h"
#include "Runkin_LR3-4_Painting.cpp"
#include <ctime>
#include <functional>
#include <iostream>
#include <map>

using namespace std;

// Структура для элемента меню
struct MenuItem {
  string title;
  function<void()> action;
};

int main() {
  // Генерация начального случайного значения
  srand(static_cast<unsigned>(time(NULL)));

  // Создание меню с использованием std::map
  map<int, MenuItem> menu = {
      {1, {"Create a painting", []() { inputPainting(); }}},
      {2, {"Display all paintings", displayAllPaintings}},
      {3, {"Demonstrate constructors", demonstrateConstructors}},
      {4, {"Demonstrate methods", demonstrateMethods}},
      {5, {"Sort paintings by year creation", sortPaintingsByYearCreation}},
  };

  int choice = 0; // Переменная для хранения выбора пользователя

  cout << "Menu: " << endl;
  // Вывод всех пунктов меню
  for (const auto &item : menu) {
    cout << "Task " << item.first << ". " << item.second.title << endl;
  }
  cout << "0. Exit" << endl; // Пункт для выхода из программы

  while (true) {
    EnterNumber(choice, "Enter the task number: ");
    // Выход из программы, если выбран пункт 0
    if (choice == 0) {
      cout << " 2025 Your Name" << endl;
      break;
    }
    cout << endl << "=========Action:===========" << endl;

    // Проверка, существует ли выбранный пункт меню
    if (menu.find(choice) != menu.end()) {
      menu[choice].action(); // Выполнение действия, связанного с пунктом меню
    } else {
      cout << "Incorrect input."
           << endl; // Сообщение об ошибке, если пункт не найден
    }
    cout << endl; // Отступ для красоты
  }
  return 0; // Завершение программы
}