#include "Runkin_LR3-4_Painting.cpp"
#include <ctime>

using namespace std;
int main() {
  // генерация начального случайного значения
  srand(time(NULL));

  // Создание меню с использованием std::map
  map<int, MenuItem> menu = {
      // {1, {"Create Polynom Constructor default", createPolDefault}},
      // {2, {"Create Polynom Constructor with degree", createPolDeg}},
      // {3, {"Create Polynom Constructor with degree & coefficients",
      // createPolDegCoeff}},
      // {4, {"Create Polynom with consol", createPolCons}},
      // {5, {"Show array of Polynom", showArrayPol (vectorOfAllPolynoms)}},
      // {6, {"Calculate value of Polynom", calcvalPol}},
      // {7, {"Add of Polynoms", addPolynoms}},
      // {8, {"Sum of array the Polynoms", sumArrPolynoms}}
  };
  unsigned choice = 0; // Переменная для хранения выбора пользователя
                       // Основной цикл программы
                       // while (true) {
  std::cout << "Меню: " << std::endl;
  // Вывод всех пунктов меню
  for (const auto &item : menu) {
    std::cout << "Task " << item.first << ". " << item.second.title
              << std::endl;
  }
  std::cout << "0. Выход" << std::endl; // Пункт для выхода из программы

  while (true) {
    EnterNumber(choice, "Введите номер пункта: ")();
    // Выход из программы, если выбран пункт 0
    if (choice == 0) {
      std::cout << "© 2025 FirstName LastName" << std::endl;
      break;
    }
    cout << endl << "=========Action:===========" << endl;

    // Проверка, существует ли выбранный пункт меню
    if (menu.find(choice) != menu.end()) {
      menu[choice].action(); // Выполнение действия, связанного с пунктом меню
    } else {

      std::cout << "Некорректный ввод.";
    } // Сообщение об ошибке, если пункт не найден
    std::cout << std::endl; // Отступ для красоты
  }
  return 0; // Завершение программы
}