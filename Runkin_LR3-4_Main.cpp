#include "RUNKIN_LR3-4_Methods.h"
#include "RUNKIN_LR3-4_Painting.h"
#include "Runkin_LR3-4_Painting.cpp"

using namespace std;

struct MenuItem {
  string title;
  function<void()> action;
};

int main() {
  // Инициализация меню
  map<int, MenuItem> menu = {
      {1, {"Add Painting", addPainting}},
      {2, {"Display All Paintings", getSortedByYear}},
      {3,
       {"Load Paintings from File",
        []() {
          loadFile("Painting.txt", paintings); // Вызов функции загрузки
        }}},
  };

  int choice = 0;

  // Отображение меню
  cout << "Menu:" << endl;
  for (const auto &item : menu) {
    cout << item.first << ". " << item.second.title << endl;
  }

  cout << "0. Exit" << endl;

  while (true) {
    EnterNumber(choice, "Enter your choice: ")();
    if (choice == 0) {
      cout << "Goodbye!" << endl;
      break;
    }

    cout << endl;

    if (menu.find(choice) != menu.end()) {
      menu[choice].action();
    } else {
      cout << "Invalid choice." << endl;
    }

    cout << endl << endl;
  }

  return 0;
}